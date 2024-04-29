
#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>

#include <iostream>

// utils
bool dateValid(std::string dateStr);
bool priceValid(std::string dateStr);

// constructor
BitcoinExchange::BitcoinExchange() {}

bool BitcoinExchange::readPriceDatabase(std::string dataFile)
{
    std::ifstream ifstr;
    if (this->_fileReadable(dataFile, ifstr) == false) {
        return false;
    }
    if (this->_headerValid(ifstr) == false) {
        ifstr.close();
        return false;
    }
    if (this->_addPricesFromStream(ifstr) == false) {
        ifstr.close();
        return false;
    }
    return true;
}

bool BitcoinExchange::_fileReadable(std::string dataFile, std::ifstream &ifstr)
{
    if (dataFile == "") {
        std::cerr << "datafile not found or not readable" << std::endl;
        return false;
    }
    ifstr.open(dataFile);
    if (!ifstr) {
        std::cerr << "datafile not found or not readable" << std::endl;
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
        std::cerr << "incorrect header in data file" << std::endl;
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
        throw std::range_error("no exchange rate found!");
    }
    return (*(--it_upper)).second;
}
