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
    bool _addPricesFromStream(std::ifstream &ifstr);
};

#endif
