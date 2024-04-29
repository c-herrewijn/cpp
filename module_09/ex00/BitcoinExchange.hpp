#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange {
public:
    BitcoinExchange();
    double getExchangeRate(std::string date) const;
    bool readPriceDatabase(std::string dataFile);

private:
    std::map<std::string, double>_exchangeRates;
    static bool _fileReadable(std::string dataFile, std::ifstream &ifstr);
    static bool _headerValid(std::ifstream &ifstr);
    bool _addPricesFromStream(std::ifstream &ifstr);
};

#endif
