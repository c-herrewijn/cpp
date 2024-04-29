
#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

// utils
bool dateValid(std::string dateStr);
bool priceValid(std::string dateStr);
bool openFile(std::string dataFile, std::ifstream &ifstr);
bool validateHeader(std::ifstream &ifstr, std::string headerExpected);

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    *this = obj;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    this->_exchangeRates = obj._exchangeRates;
    return *this;
}

bool BitcoinExchange::readPriceDatabase()
{
    std::ifstream ifstr;
    if (openFile(DATABASE, ifstr) == false
            || validateHeader(ifstr, "date,exchange_rate") == false
            || this->_addPricesFromStream(ifstr) == false) {
        ifstr.close();
        return false;
    }
    if (this->_exchangeRates.size() == 0) {
        std::cerr << "Error: no prices could be stored" << std::endl;
        ifstr.close();
        return false;
    }
    ifstr.close();
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
            std::cerr << "Error: invalid csv file" << std::endl;
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
    if (this->_exchangeRates.size() == 0) {
        return (0);
    }
    auto it_upper = this->_exchangeRates.upper_bound(date);
    if (it_upper == this->_exchangeRates.begin()) {
        return (*it_upper).second;
    }
    return (*(--it_upper)).second;
}
