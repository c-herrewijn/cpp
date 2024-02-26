#include "ScalarConverter.hpp"
#include <string>
#include <limits>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>

// anonymous namespace: only visible inside the file-scope
namespace {
    typedef enum floatPrecision {
        SINGLE,
        DOUBLE
    } floatPrecision_e;

    typedef enum scalarType {
        CHAR_TYPE,
        INT_TYPE,
        FLOAT_TYPE,
        DOUBLE_TYPE,
        NONE_TYPE  // undefined
    } scalarType_e;

    typedef struct scalarSet_s {
        unsigned char c;
        int i;
        float f;
        double d;
        scalarType_e inputType;
    } scalarSet_t;
}

// valid input: single quoted char
static void parseAsChar(std::string str, scalarSet_t &scalarSet)
{
    if (str.length() == 3
            && (str.c_str()[0] == '\'')
            && std::isprint(str.c_str()[1])
            && (str.c_str()[2] == '\'')) {
        scalarSet.inputType = CHAR_TYPE;
        scalarSet.c = str.c_str()[1];
    }
}

// valid input: numerical value in range [INT_MIN, INT_MAX]
static void parseAsInt(std::string str, scalarSet_t &scalarSet)
{
    try {
        int num = std::stoi(str);
        if (std::to_string(num) == str) {
            scalarSet.inputType = INT_TYPE;
            scalarSet.i = static_cast<int>(num);
        }
    }
    catch (std::invalid_argument &e) {}
    catch (std::out_of_range &e) {}
}

static void parseAsDouble(std::string str, scalarSet_t &scalarSet)
{
    floatPrecision_e fPrecision;
    if (str.back() == 'f' && str != "inf" && str != "-inf") {
        str.pop_back();
        fPrecision = SINGLE;
    }
    else {
        fPrecision = DOUBLE;
    }

    // special values
    double num;
    if (str == "nan" || str == "inf" || str == "-inf") {
        if (str == "nan") {
            num = std::numeric_limits<double>::quiet_NaN();
        }
        if (str == "inf") {
            num = std::numeric_limits<double>::infinity();
        }
        if (str == "-inf") {
            num = -std::numeric_limits<double>::infinity();
        }
        scalarSet.d = num;
        if (fPrecision == SINGLE) {
            scalarSet.inputType = FLOAT_TYPE;
            scalarSet.f = static_cast<float>(num);
        }
        if (fPrecision == DOUBLE) {
            scalarSet.inputType = DOUBLE_TYPE;
        }
        scalarSet.d = num;
    }

    // special values
    if (scalarSet.inputType == NONE_TYPE) {
        try {
            if (fPrecision == SINGLE) {
                num = std::stof(str);
                scalarSet.inputType = FLOAT_TYPE;
                scalarSet.f = static_cast<float>(num);
            }
            if (fPrecision == DOUBLE) {
                num = std::stod(str);
                scalarSet.inputType = DOUBLE_TYPE;
            }
            scalarSet.d = num;
        }
        catch (std::invalid_argument &e) {}
        catch (std::out_of_range &e) {}
    }
}

static void parseInput(std::string str, scalarSet_t &scalarSet)
{
    if (scalarSet.inputType == NONE_TYPE) {
        parseAsChar(str, scalarSet);
    }
    if (scalarSet.inputType == NONE_TYPE) {
        parseAsInt(str, scalarSet);
    }
    if (scalarSet.inputType == NONE_TYPE) {
        parseAsDouble(str, scalarSet);
    }
}

// converts all to doubles, and char also to int
static void convertScalars(scalarSet_t &scalarSet)
{
    if (scalarSet.inputType == INT_TYPE) {
        scalarSet.d = static_cast<double>(scalarSet.i);
    }
    if (scalarSet.inputType == CHAR_TYPE) {
        scalarSet.d = static_cast<double>(scalarSet.c);
        scalarSet.i = static_cast<int>(scalarSet.c);
    }
    if (scalarSet.inputType == FLOAT_TYPE) {
        scalarSet.d = static_cast<double>(scalarSet.f);
    }
}

static void printScalars(scalarSet_t &scalarSet)
{
    std::string charStr = "";
    std::string intStr = "";
    std::string floatStr = "";
    std::string doubleStr = "";

    // impossible
    if (scalarSet.inputType == NONE_TYPE) {
        charStr = "impossible";
        intStr = "impossible";
        floatStr = "impossible";
        doubleStr = "impossible";
    }

    // inf, -inf, nan
    else if (scalarSet.d == std::numeric_limits<double>::infinity()
             || scalarSet.d == -std::numeric_limits<double>::infinity()
             || std::isnan(scalarSet.d)) {
        charStr = "impossible";
        intStr = "impossible";
    }

    // not fitting in floats
    else if (scalarSet.d > std::numeric_limits<float>::max()
             || scalarSet.d < -std::numeric_limits<float>::max()
             || (fabs(scalarSet.d) < std::numeric_limits<float>::min()
                 && scalarSet.d != 0)) {
        charStr = "impossible";
        intStr = "impossible";
        floatStr = "impossible";
    }

    // not fitting in int
    else if (scalarSet.d > std::numeric_limits<int>::max()
             || scalarSet.d < std::numeric_limits<int>::min()) {
        charStr = "impossible";
        intStr = "impossible";
    }
    else {
        // within int range
        scalarSet.i = static_cast<int>(scalarSet.d);
        intStr = std::to_string(scalarSet.i);

        // displayable:
        if (scalarSet.i <= 255 && scalarSet.i >= 0 && std::isprint(scalarSet.i)) {
            charStr = "'";
            charStr += scalarSet.i;
            charStr += "'";
        }
        else {
            if (scalarSet.i <= 255 && scalarSet.i >= 0) {
                charStr = "Non displayable";
            }
            else {
                charStr = "impossible";
            }
        }
    }

    // normal double value
    if (doubleStr == "") {
        std::stringstream ss;
        if (scalarSet.d == scalarSet.i && fabs(scalarSet.d) < 1e6) {
            ss << std::fixed << std::setprecision(1) << scalarSet.d;
        }
        else {
            ss << scalarSet.d;
        }
        doubleStr = ss.str();
        if (floatStr == "") {
            floatStr = doubleStr;
            if (fabs(scalarSet.d) < 1e6 || floatStr == "inf" || floatStr == "-inf"
                    || floatStr == "nan") {
                floatStr += 'f';
            }
        }
    }
    std::cout << "char: " << charStr << std::endl
              << "int: " << intStr << std::endl
              << "float: " << floatStr << std::endl
              << "double: " << doubleStr << std::endl;
}

void ScalarConverter::convert(std::string scalarStr)
{
    scalarSet_t scalarSet;
    scalarSet.inputType = NONE_TYPE;

    parseInput(scalarStr, scalarSet);
    convertScalars(scalarSet);
    printScalars(scalarSet);
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
