
#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>

#include <iostream>

bool dateValid(std::string dateStr);
bool priceValid(std::string dateStr);

bool BitcoinExchange::_fileReadable(std::string dataFile, std::ifstream &ifstr)
{
    if (dataFile == "") {
        return false;
    }
    ifstr.open(dataFile);
    if (!ifstr) {
        return false;
    }
    return true;
}

bool BitcoinExchange::_headerValid(std::ifstream &ifstr)
{
    std::string header;
    std::getline(ifstr, header);
    std::string headerExpected = "date,exchange_rate";
    if (headerExpected != header) {
        return false;
    }
    return true;
}

bool BitcoinExchange::_addPricesFromStream(std::ifstream &ifstr)
{
    for (std::string csv_line; std::getline(ifstr, csv_line);) {
        std::istringstream ss(csv_line);
        std::string date;
        std::string exchangeRateStr;
        getline(ss, date, ',');
        ss >> exchangeRateStr;
        if (ss.eof() == false
                || dateValid(date) == false
                || priceValid(exchangeRateStr) == false) {
            return false;
        }
        this->_exchangeRates.emplace(date, std::stod(exchangeRateStr));
    }
    return true;
}

BitcoinExchange::BitcoinExchange(std::string dataFile)
{
    std::ifstream ifstr;
    if (this->_fileReadable(dataFile, ifstr) == false) {
        throw std::runtime_error("datafile not found or not readable");
    }
    if (this->_headerValid(ifstr) == false) {
        ifstr.close();
        throw std::runtime_error("incorrect header in data file");
    }
    if (this->_addPricesFromStream(ifstr) == false) {
        ifstr.close();
        throw std::runtime_error("invalid csv line");
    }
}

double BitcoinExchange::getExchangeRate(std::string date)
{
    return (42.); // TODO;
}
