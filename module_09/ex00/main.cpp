#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "BitcoinExchange.hpp"

/*
checks if format is yyyy-mm-dd
*/
bool dateValid(std::string dateStr)
{
    char c1, c2;
    unsigned int y, m, d;
    std::stringstream ss(dateStr);
    ss >> y >> c1 >> m >> c2 >> d;
    return (ss.eof() == true
            && (y >= 1899 && y < 9999)
            && (m >= 1 && m <= 12)
            && (d >= 1 && d <= 31)
            && (d <= 28 || m != 2 || (y % 4 == 0 && (y % 100 != 0
                                      || y % 400 == 0))) // leap year check
            && (d <= 29 || m != 2)
            && (d <= 30 || m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10
                || m == 12)
            && (c1 == '-')
            && (c2 == '-')
           );
}

/*
accepted price formats:
- whole numbers: [dollars]
- dollars and cents [dollars].[cents]
*/
bool priceValid(std::string dateStr)
{
    char c1;
    int dollars, cents;
    bool noDelimitor = false;
    std::stringstream ss(dateStr);

    ss >> dollars;
    if (ss.eof() == true) {
        noDelimitor = true;
        cents = 0;
    }
    else {
        ss >> c1 >> cents;
    }
    return (ss.eof() == true
            && (dollars >= 0)
            && (cents >= 0 && cents < 100)
            && (noDelimitor == true || c1 == '.')
           );
}

bool inputValid(int argc, char *argv[])
{
    // todo: also validate argv[2]
    if (argc != 2) {
        if (argc < 2) {
            std::cerr << "Error: invalid number of argumets, no datafile provided\n";
        }
        else {
            std::cerr << "Error: invalid number of argumets\n";
        }
        return false;
    }
    else {
        return true;
    }
}

int main(int argc, char *argv[])
{
    BitcoinExchange exchange;
    if (inputValid(argc, argv) == false) {
        exit(EXIT_FAILURE);
    }

    if (exchange.readPriceDatabase("data.csv") == false) {
        exit(EXIT_FAILURE);
    }
}
