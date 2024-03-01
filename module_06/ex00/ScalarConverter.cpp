#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <limits>

namespace {
    typedef enum inputType_e {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        NONE_TYPE
    } inputType_t;

    typedef struct conversions_s {
        char c;
        std::string cMessage;
        int i;
        std::string iMessage;
        float f;
        std::string fMessage;
        double d;
        std::string dMessage;
    } conversions_t;
}

// valid chars: single quoted chars, or non-numeric printable chars
static bool isChar(std::string str, conversions_t &conversions)
{
    char c;

    if (str.length() == 3 && str[0] == '\'' && std::isprint(str[1])
            && str[2] == '\'') {
        c = str[1];
    }
    else if (str.length() == 1 && std::isprint(str[0])
             && std::isdigit(str[0]) == false) {
        c = str[0];
    }
    else {
        return false;
    }
    conversions.c = c;
    return (true);
}

static bool isInt(std::string str, conversions_t &conversions)
{
    int sign = str[0] == '-' ? -1 : 1;
    if (sign == -1) {
        str.erase(str.begin());
    }
    if (str.length() > std::numeric_limits<int>::digits10 + 1) {
        return false;
    }
    for (char c : str) {
        if (std::isdigit(c) == false) {
            return false;
        }
    }
    long li = sign * std::stol(str);
    if (li > std::numeric_limits<int>::max()
            || li < std::numeric_limits<int>::min()) {
        return false;
    }
    conversions.i = static_cast<int>(li);
    return (true);
}

static bool isFloat(std::string str, conversions_t &conversions)
{
    return false;
}

static bool isDouble(std::string str, conversions_t &conversions)
{
    return false;
}

static void convertChar(std::string scalarStr, conversions_t &conversions)
{
    conversions.i = static_cast<int>(conversions.c);
    conversions.f = static_cast<float>(conversions.c);
    conversions.d = static_cast<double>(conversions.c);
}

static void convertInt(std::string scalarStr, conversions_t &conversions)
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
    conversions.f = static_cast<float>(conversions.i);
    conversions.d = static_cast<double>(conversions.i);
}

static void convertFloat(std::string scalarStr, conversions_t &conversions)
{

}

static void convertDouble(std::string scalarStr, conversions_t &conversions)
{

}

static void printConversions(conversions_t &conversions)
{
    if (conversions.cMessage == "") {
        std::cout << "char: '" << conversions.c << "'" << std::endl;
    }
    else {
        std::cout << "char: " << conversions.cMessage << std::endl;
    }
    if (conversions.iMessage == "") {
        std::cout << "int: " << conversions.i << std::endl;
    }
    else {
        std::cout << "int: " << conversions.iMessage << std::endl;
    }
    if (conversions.fMessage == "") {
        std::cout << "float: " << conversions.f << std::endl;
    }
    else {
        std::cout << "float: "<< conversions.fMessage << std::endl;
    }
    if (conversions.dMessage == "") {
        std::cout << "double: " << conversions.d << std::endl;
    }
    else {
        std::cout << "double: "<< conversions.dMessage << std::endl;
    }
}

void ScalarConverter::convert(std::string scalarStr)
{
    inputType_t inputType;
    conversions_t conversions = {};

    // general validation
    if (scalarStr == "") {
        inputType = NONE_TYPE;
    }

    // detect input type
    else if (isChar(scalarStr, conversions)) {
        inputType = CHAR;
    }
    else if (isInt(scalarStr, conversions)) {
        inputType = INT;
    }
    else if (isFloat(scalarStr, conversions)) {
        inputType = FLOAT;
    }
    else if (isDouble(scalarStr, conversions)) {
        inputType = DOUBLE;
    }
    else {
        inputType = NONE_TYPE;
    }

    // convert input type
    if (inputType == CHAR) {
        convertChar(scalarStr, conversions);
    }
    if (inputType == INT) {
        convertInt(scalarStr, conversions);
    }

    // print
    if (inputType != NONE_TYPE) {
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
