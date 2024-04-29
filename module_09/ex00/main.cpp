#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <stdexcept>

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

bool openFile(std::string dataFile, std::ifstream &ifstr)
{
    ifstr.open(dataFile);
    if (!ifstr) {
        std::cerr << "file '" + dataFile + "' not found or not readable" << std::endl;
        return false;
    }
    return true;
}

bool validateHeader(std::ifstream &ifstr, std::string headerExpected)
{
    std::string header;
    std::getline(ifstr, header);
    if (headerExpected != header) {
        std::cerr << "incorrect header in data file" << std::endl;
        return false;
    }
    return true;
}

// trim string from end (in place)
static void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static bool inputValid(int argc, char *argv[], std::ifstream &inputStream)
{
    if (argc != 2) {
        std::cerr << "Error: invalid number of argumets\n";
        return false;
    }
    if (openFile(argv[1], inputStream) == false
            || validateHeader(inputStream, "date | value") == false) {
        inputStream.close();
        return false;
    }
    return true;
}

static void calcBitcoinValue(BitcoinExchange &exchange, std::string csv_line)
{
    std::istringstream ss(csv_line);
    std::string date;
    double amount;
    getline(ss, date, '|');
    rtrim(date);
    if (ss.eof() == true) {
        std::cerr << "Error: bad input => " << csv_line << std::endl;
    }
    else {
        ss >> amount;
        if (ss.eof() == false) {
            std::cerr << "Error: bad input => " << csv_line << std::endl;
        }
        else if (dateValid(date) == false) {
            std::cerr << "Error: bad input => " << csv_line << std::endl;
        }
        else if (amount < 0) {
            std::cerr << "Error: not a positive number" << std::endl;
        }
        else if (amount > INT32_MAX) {
            std::cerr << "Error: number too large" << std::endl;
        }
        else {
            try {
                double price = exchange.getExchangeRate(date);
                std::cout << date << " => " << amount << " = " << (price * amount) << std::endl;
            }
            catch (std::range_error &e) {
                std::cerr << "Error: " << e.what() << " for date " << date << std::endl;
            }
        }
    }
}

static void calcBitcoinValuesFromFile(BitcoinExchange &exchange,
                                      std::ifstream &inputAmounts)
{
    for (std::string csv_line; std::getline(inputAmounts, csv_line);) {
        calcBitcoinValue(exchange, csv_line);
    }
}

int main(int argc, char *argv[])
{
    std::ifstream inputAmounts;
    if (inputValid(argc, argv, inputAmounts) == false) {
        exit(EXIT_FAILURE);
    }
    BitcoinExchange exchange;
    if (exchange.readPriceDatabase("data.csv") == false) {
        exit(EXIT_FAILURE);
    }
    calcBitcoinValuesFromFile(exchange, inputAmounts);
    inputAmounts.close();
}
