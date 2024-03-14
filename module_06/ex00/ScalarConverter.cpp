#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <cmath>
#include <sstream>

// valid chars: single quoted chars, or non-numeric chars
bool ScalarConverter::_parseChar(std::string str, conversions_t &conversions)
{
    char c = '\0';
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

// valid inputs are within range [INT_MIN and INT_MAX], no decimal point allowed
bool ScalarConverter::_parseInt(std::string str, conversions_t &conversions)
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
    conversions.i = static_cast<int>(li);
    _convertIntToChar(conversions);
    _convertIntToFloat(conversions);
    conversions.d = static_cast<double>(conversions.i);
    return (true);
}

/*
FORMAT:
decimal format or 'nan', 'inf', or '-inf'. Exponential format is not supported
floats shoud append an extra 'f', also for the special formats: 'nanf', 'inff', or '-inff'
decimals should contain a decimal separator '.', and should contain max 18 digits
NOTE: float and doubles do not guarantee exact representation
*/
bool ScalarConverter::_parseFloatDouble(std::string str, conversions_t &conversions)
{
    floatingStrLiteral_t num;
    if (str.back() == 'f') {
        str.pop_back();
        num.type = SINGLE_PRECISION;
    }
    else
        num.type = DOUBLE_PRECISION;

    if (_parseNaNOrInf(str, conversions))
        return true;
    if (_validDecimalFormat(str, num)) {
        conversions.numDigitsBehindDecimalPoint = num.numDigitsBehindDecimalPoint;
        if (num.type == SINGLE_PRECISION) {
            conversions.f = static_cast<float>(num.sign) * std::stof(str);
            conversions.fMessage = num.warning;
            conversions.d = static_cast<double>(conversions.f);
        }
        else {
            conversions.d = static_cast<double>(num.sign) * std::stod(str);
            conversions.dMessage = num.warning;
            _convertDoubleToFloat(conversions);
        }
        _convertDoubleToInt(conversions);
        _convertIntToChar(conversions);
        return true;
    }
    return (false);
}

bool ScalarConverter::_parseNaNOrInf(std::string str, conversions_t &conversions) {
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

void ScalarConverter::_convertIntToChar(conversions_t &conversions)
{
    if (conversions.iMessage != ""
        ||conversions.i > std::numeric_limits<char>::max()
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

void ScalarConverter::_convertIntToFloat(conversions_t &conversions) {
    float f = static_cast<float>(conversions.i);
    if (static_cast<double>(f) != static_cast<double>(conversions.i)) {
        conversions.fMessage = " (integer can not be exactly represented in float)";
    }
    conversions.f = f;
}

void ScalarConverter::_convertDoubleToFloat(conversions_t &conversions) {
    float f = static_cast<float>(conversions.d);
    conversions.f = f;
    if (_floatingTypeToString(conversions, SINGLE_PRECISION) != _floatingTypeToString(conversions, DOUBLE_PRECISION)) {
        conversions.fMessage = " (differs because exact representation is not possible)";
    }
}

void ScalarConverter::_convertDoubleToInt(conversions_t &conversions)
{
    if (conversions.d > std::numeric_limits<int>::max()
            || conversions.d < std::numeric_limits<int>::min()) {
        conversions.iMessage = "impossible (floating point input is outside the integer range)";
    }
    else {
        conversions.i = static_cast<int>(conversions.d);
    }
}

void ScalarConverter::_printConversions(conversions_t &conversions)
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
    else
        std::cout << "int: " << conversions.iMessage << std::endl;

    // float
    if (conversions.fMessage == "")
        std::cout << "float: " << _floatingTypeToString(conversions, SINGLE_PRECISION) << "f" << std::endl;
    else if (conversions.fMessage == "impossible")
        std::cout << "float: " << conversions.fMessage << std::endl;
    else
        std::cout << "float: " << _floatingTypeToString(conversions, SINGLE_PRECISION) << "f" << conversions.fMessage << std::endl;

    // double
    if (conversions.dMessage == "")
        std::cout << "double: " << _floatingTypeToString(conversions, DOUBLE_PRECISION) << std::endl;
    else
        std::cout << "double: " << _floatingTypeToString(conversions, DOUBLE_PRECISION) << conversions.dMessage << std::endl;
}

std::string ScalarConverter::_floatingTypeToString(conversions_t &conversions, floatingType_t type) {
    std::stringstream ss;
    const int defaultPrecision = static_cast<int>(std::cout.precision());
    int precision = (conversions.numDigitsBehindDecimalPoint == 0) ? 1 : conversions.numDigitsBehindDecimalPoint;

    if (type == SINGLE_PRECISION)
        ss << std::fixed << std::setprecision(precision) << conversions.f << std::setprecision(defaultPrecision);
    else
        ss << std::fixed << std::setprecision(precision) << conversions.d << std::setprecision(defaultPrecision);
    return ss.str();
}

bool ScalarConverter::_validDecimalFormat(std::string &str, floatingStrLiteral_t &n)
{
    n.numDigits = 0;
    n.hasRadixPoint = false;
    n.sign = (str[0] == '-') ? -1 : 1;
    n.numDigitsBehindDecimalPoint = 0;
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
    int digits10 = (n.type == SINGLE_PRECISION)
        ? std::numeric_limits<float>::digits10
        : std::numeric_limits<double>::digits10;
    if (n.hasRadixPoint == false || n.numDigits == 0 || n.numDigits > std::numeric_limits<long double>::digits10)
        return false;
    if (n.numDigits > digits10)
        n.warning = " (only " + std::to_string(digits10) + " digits of precision can be guaranteed)";
    return true;
}

void ScalarConverter::convert(std::string scalarStr)
{
    conversions_t conversions = {};
    if (scalarStr != "" && (_parseChar(scalarStr, conversions)
                            || _parseInt(scalarStr, conversions)
                            || _parseFloatDouble(scalarStr, conversions)))
    {
        _printConversions(conversions);
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
