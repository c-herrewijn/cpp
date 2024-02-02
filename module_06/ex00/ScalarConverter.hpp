#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <string>

class ScalarConverter {

public:
    static void convert(std::string scalarStr);

private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &obj);
    ScalarConverter &operator=(const ScalarConverter &obj);
};

#endif
