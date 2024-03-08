#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <cmath>
#include <sstream>

namespace {
    typedef enum floatingType_e {
        SINGLE_PRECISION,
        DOUBLE_PRECISION
    } floatingType_t;

    typedef struct conversions_s {
        char c;
        std::string cMessage;
        int i;
        std::string iMessage;
        float f;
        std::string fMessage;
        double d;
        std::string dMessage;
        int numDigitsBehindDecimalPoint = 0;
    } conversions_t;

    typedef struct floatingStrLiteral_s {
        floatingType_t type;
        int numDigits;
        bool hasRadixPoint;
        int sign;
        int numDigitsBehindDecimalPoint;
    } floatingStrLiteral_t;
}

static void convertIntToChar(conversions_t &conversions)
{
    if (conversions.i > std::numeric_limits<char>::max()
            || conversions.i < std::numeric_limits<char>::min()) {
        conversions.cMessage = "impossible";
    }
    else if (std::isprint(static_cast<char>(conversions.i)) == false) {
        conversions.cMessage = "Non displayable";
    }
    else {
        conversions.c = static_cast<char>(conversions.i);
    }
}

static void convertIntToFloat(conversions_t &conversions) {
    float f = static_cast<float>(conversions.i);
    if (static_cast<double>(f) != static_cast<double>(conversions.i)) {
        conversions.fMessage = " (integer can not be exactly represented in float)";
    }
    conversions.f = f;
}

static std::string floatingTypeToString(conversions_t &conversions, floatingType_t type) {
    std::stringstream ss;
    const int defaultPrecision = static_cast<int>(std::cout.precision());
    int precision = (conversions.numDigitsBehindDecimalPoint == 0) ? 1 : conversions.numDigitsBehindDecimalPoint;

    if (type == SINGLE_PRECISION)
        ss << std::fixed << std::setprecision(precision) << conversions.f << std::setprecision(defaultPrecision);
    else
        ss << std::fixed << std::setprecision(precision) << conversions.d << std::setprecision(defaultPrecision);
    return ss.str();
}

static void convertDoubleToFloat(conversions_t &conversions) {
    float f = static_cast<float>(conversions.d);
    conversions.f = f;
    if (floatingTypeToString(conversions, SINGLE_PRECISION) != floatingTypeToString(conversions, DOUBLE_PRECISION)) {
        conversions.fMessage = " (differs because exact representation is not possible)";
    }
}

static void convertDoubleToInt(conversions_t &conversions)
{
    if (conversions.d > std::numeric_limits<int>::max()
            || conversions.d < std::numeric_limits<int>::min()) {
        conversions.iMessage = "impossible";
    }
    else {
        conversions.i = static_cast<int>(conversions.d);
    }
}

// valid chars: single quoted chars, or non-numeric chars
static bool parseChar(std::string str, conversions_t &conversions)
{
    char c = '\0';
    bool charInput = false;

    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
        c = str[1];
    }
    else if (str.length() == 1 && std::isdigit(str[0]) == false) {
        c = str[0];
    }
    else {
        return false;
    }
    conversions.c = c;
    conversions.i = static_cast<int>(conversions.c);
    conversions.f = static_cast<float>(conversions.c);
    conversions.d = static_cast<double>(conversions.c);
    return (true);
}

static bool parseInt(std::string str, conversions_t &conversions)
{
    int sign = str[0] == '-' ? -1 : 1;
    if (sign == -1) {
        str.erase(str.begin());
    }
    for (char c : str) {
        if (std::isdigit(c) == false) {
            return false;
        }
    }
    if (str.length() > std::numeric_limits<int>::digits10 + 1) {
        return false;
    }
    long li = sign * std::stol(str);
    if (li > std::numeric_limits<int>::max()
            || li < std::numeric_limits<int>::min()) {
        return false;
    }

    // conversions
    conversions.i = static_cast<int>(li);
    convertIntToChar(conversions);
    convertIntToFloat(conversions);
    conversions.d = static_cast<double>(conversions.i);
    return (true);
}

static bool parseNaNOrInf(std::string str, conversions_t &conversions) {
    if (str == "nan" || str == "inf" || str == "-inf") {
        if (str == "nan") {
            conversions.f = std::numeric_limits<float>::quiet_NaN();
            conversions.d = std::numeric_limits<double>::quiet_NaN();
        }
        if (str == "inf") {
            conversions.f = std::numeric_limits<float>::infinity();
            conversions.d = std::numeric_limits<double>::infinity();
        }
        if (str == "-inf") {
            conversions.f = -std::numeric_limits<float>::infinity();
            conversions.d = -std::numeric_limits<double>::infinity();
        }
        conversions.cMessage = "impossible";
        conversions.iMessage = "impossible";
        return true;
    }
    return false;
}

static bool parseDecimalFormat(std::string &str, floatingStrLiteral_t &n)
{
    n.numDigits = 0;
    n.hasRadixPoint = false;
    n.sign = (str[0] == '-') ? -1 : 1;
    n.numDigitsBehindDecimalPoint = 0;

    int digits10;
    if (n.type == SINGLE_PRECISION)
        digits10 = std::numeric_limits<float>::digits10;
    else
        digits10 = std::numeric_limits<double>::digits10;

    if (n.sign == -1) {
        str.erase(str.begin());
    }
    for (char c : str) {
        if (std::isdigit(c)) {
            n.numDigits++;
            if (n.hasRadixPoint == true)
                n.numDigitsBehindDecimalPoint++;
        }
        else if (c == '.' && (n.hasRadixPoint == false))
            n.hasRadixPoint = true;
        else
            return false;
    }
    if (n.hasRadixPoint == false || n.numDigits == 0 || n.numDigits > digits10) {
        return false;
    }
    return true;
}


// is decimal number within range of float. NOTE: this does NOT guarantee exact representation
static bool parseFloatOrDouble(std::string str, conversions_t &conversions)
{
    floatingStrLiteral_t num;
    if (str.back() == 'f') {
        str.pop_back();
        num.type = SINGLE_PRECISION;
    }
    else
        num.type = DOUBLE_PRECISION;

    if (parseNaNOrInf(str, conversions))
        return true;

    if (parseDecimalFormat(str, num)) {
        conversions.numDigitsBehindDecimalPoint = num.numDigitsBehindDecimalPoint;
        if (num.type == SINGLE_PRECISION) {
            conversions.f = static_cast<float>(num.sign) * std::stof(str);
            conversions.d = static_cast<double>(conversions.f);
        }
        else {
            conversions.d = static_cast<double>(num.sign) * std::stod(str);
            convertDoubleToFloat(conversions);
        }
        convertDoubleToInt(conversions);
        convertIntToChar(conversions);
        return true;
    }
    return (false);
}

static void printConversions(conversions_t &conversions)
{
    // char
    if (conversions.cMessage == "") {
        if (std::isprint(conversions.c))
            std::cout << "char: '" << conversions.c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else {
        std::cout << "char: " << conversions.cMessage << std::endl;
    }

    // int
    if (conversions.iMessage == "")
        std::cout << "int: " << conversions.i << std::endl;
    else if (conversions.iMessage == "impossible")
        std::cout << "int: " << conversions.iMessage << std::endl;
    else
        std::cout << "int: " << conversions.i << conversions.iMessage << std::endl;

    // float
    if (conversions.fMessage == "")
        std::cout << "float: " << floatingTypeToString(conversions, SINGLE_PRECISION) << "f" << std::endl;
    else if (conversions.fMessage == "impossible")
        std::cout << "float: " << conversions.fMessage << std::endl;
    else
        std::cout << "float: " << floatingTypeToString(conversions, SINGLE_PRECISION) << "f" << conversions.fMessage << std::endl;

    // double
    if (conversions.dMessage == "")
        std::cout << "double: " << floatingTypeToString(conversions, DOUBLE_PRECISION) << std::endl;
    else
        std::cout << "double: "<< conversions.dMessage << std::endl;
}

void ScalarConverter::convert(std::string scalarStr)
{
    conversions_t conversions = {};
    if (scalarStr != "" && (parseChar(scalarStr, conversions)
                            || parseInt(scalarStr, conversions)
                            || parseFloatOrDouble(scalarStr, conversions)))
    {
        printConversions(conversions);
    }
    else {
        std::cout << "invalid input" << std::endl;
    }
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return *this;
}
