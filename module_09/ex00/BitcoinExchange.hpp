#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# define DATABASE "data.csv"

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    double getExchangeRate(std::string date) const;
    bool readPriceDatabase();

private:
    std::map<std::string, double>_exchangeRates;
    bool _addPricesFromStream(std::ifstream &ifstr);
};

#endif
