#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <string>

class ScalarConverter {

public:
    static void convert(std::string scalarStr);

private:
    typedef struct conversions_s {
        char c;
        int i;
        float f;
        double d;
        std::string cMessage;
        std::string iMessage;
        std::string fMessage;
        std::string dMessage;
        int numDigitsBehindDecimalPoint = 0;
    } conversions_t;

    typedef enum floatingType_e {
        SINGLE_PRECISION,
        DOUBLE_PRECISION
    } floatingType_t;

    typedef struct floatingStrLiteral_s {
        floatingType_t type;
        int numDigits;
        bool hasRadixPoint;
        int sign;
        int numDigitsBehindDecimalPoint;
        std::string warning;
    } floatingStrLiteral_t;

    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter &operator=(const ScalarConverter &obj);

    // parse
    static bool _parseChar(std::string str, conversions_t &conversions);
    static bool _parseInt(std::string str, conversions_t &conversions);
    static bool _parseFloatDouble(std::string str, conversions_t &conversions);
    static bool _parseNaNOrInf(std::string str, conversions_t &conversions);

    // convert
    static void _convertIntToChar(conversions_t &conversions);
    static void _convertIntToFloat(conversions_t &conversions);
    static void _convertDoubleToFloat(conversions_t &conversions);
    static void _convertDoubleToInt(conversions_t &conversions);

    //print
    static void _printConversions(conversions_t &conversions);

    // utils
    static bool _validDecimalFormat(std::string &str, floatingStrLiteral_t &n);
    static std::string _floatingTypeToString(conversions_t &conversions,
        floatingType_t type);
};

#endif
