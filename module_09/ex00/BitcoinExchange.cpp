
#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>

#include <iostream>

// utils
bool dateValid(std::string dateStr);
bool priceValid(std::string dateStr);
bool openFile(std::string dataFile, std::ifstream &ifstr);
bool validateHeader(std::ifstream &ifstr, std::string headerExpected);

// constructor
BitcoinExchange::BitcoinExchange() {}

bool BitcoinExchange::readPriceDatabase(std::string dataFile)
{
    std::ifstream ifstr;
    if (openFile(dataFile, ifstr) == false
            || validateHeader(ifstr, "date,exchange_rate") == false
            || this->_addPricesFromStream(ifstr) == false) {
        ifstr.close();
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
            std::cerr << "invalid csv file" << std::endl;
            return false;
        }
        this->_exchangeRates.emplace(date, std::stod(exchangeRateStr));
    }
    return true;
}

double BitcoinExchange::getExchangeRate(std::string date) const
{
    if (this->_exchangeRates.find(date) != this->_exchangeRates.end()) {
        return this->_exchangeRates.at(date);
    }

    auto it_upper = this->_exchangeRates.upper_bound(date);
    if (it_upper == this->_exchangeRates.begin()
            || it_upper == this->_exchangeRates.end()) {
        throw std::range_error("no exchange rate found");
    }
    return (*(--it_upper)).second;
}
