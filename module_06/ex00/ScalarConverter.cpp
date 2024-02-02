#include "ScalarConverter.hpp"
#include <string>
#include <limits>

namespace {
    enum scalarType {
        CHAR_TYPE,
        INT_TYPE,
        FLOAT_TYPE,
        DOUBLE_TYPE,
        NONE_TYPE
    };

    typedef struct scalarSet_s {
        char c;
        int i;
        float f;
        double d;
    } scalarSet_t;

    typedef struct generalScalar_s {
        scalarType type;
        unsigned char data[sizeof(double)];
    } generalScalar_t;
}

// static double scalarToDouble(scalarType &scalar)
// {
//     (void)scalar;
//     return 42.0;
// }

// static void doubleoDouble(double &d)
// {
//     (void)d;
// }

static bool isNum(char c)
{
    return (c >= '0' && c <= '9');
}

static bool isPrint(char c)
{
    return (c >= 32 && c <= 126);
}

static bool isFloatWord(std::string str)
{
    return (str == "nan" || str == "-nan"
            || str == "inf" || str == "-inf");
}

static bool isNumericMaxOnePoint(std::string str)
{
    (void)str; // debug
    return (true); // dummy!!
}

static bool isExpNotation(std::string str)
{
    (void)str; // debug
    return (true); // dummy!!
}

static bool isDouble(std::string str)
{
    return (isFloatWord(str) || isNumericMaxOnePoint(str) || isExpNotation(str));
}

static scalarType detectType(std::string str)
{

    scalarType sType = NONE_TYPE;

    if (str.length() == 1 && isPrint(str.c_str()[0]) && !isNum(str.c_str()[0])) {
        sType = CHAR_TYPE;
    }
    if (isDouble(str)) {
        sType = DOUBLE_TYPE;
    }

    // wip
    return sType;

}

void ScalarConverter::convert(std::string scalarStr)
{
    scalarType sType = detectType(scalarStr);

    (void)scalarStr; //debug
    (void)sType; //debug

    // scalarSet_t response;
    // response.c = '*';
    // response.i = 42;
    // response.f = 42.0f;
    // response.d = 42.0; // todo: represent incl. 0
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
