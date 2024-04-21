#include <set>
#include <stdexcept>

#include "Span.hpp"

Span::Span() : _maxSize(0), _size(0), _data(std::multiset<int>()) {}

Span::Span(unsigned int n) :
    _maxSize(n),
    _size(0),
    _data(std::multiset<int>())
{}

Span::Span(const Span &obj) :
    _maxSize(obj._maxSize),
    _size(obj._size),
    _data(obj._data)
{}

Span::~Span() {}

Span &Span::operator=(const Span &obj)
{
    this->_maxSize = obj._maxSize;
    this->_size = obj._size;
    this->_data = obj._data;
    return *this;
}

void Span::addNumber(int n)
{
    if (this->_size < this->_maxSize) {
        this->_data.emplace(n);
        this->_size++;
    }
    else {
        throw std::range_error("no space in span");
    }
}

void Span::insertFromVector(std::vector<int> &vect) {
    this->_data.insert(vect.begin(), vect.end());
}

unsigned int Span::shortestSpan()
{
    bool spanFound = false;
    int shortestSpan;

    if (_data.size() < 2) {
        std::string errStr = "no span found, span length = "
                             + std::to_string(_data.size()) + "!";
        throw std::logic_error(errStr);
    }
    for (auto it=this->_data.begin(); it != this->_data.end(); it++) {

        if (_data.count(*it) > 1) {
            return 0;
        }
        auto nextIt = std::next(it, 1);
        if (nextIt != _data.end()) {
            if (spanFound == false || *nextIt - *it < shortestSpan) {
                spanFound = true;
                shortestSpan = *nextIt - *it;
            }
        }
    }
    return static_cast<unsigned int>(shortestSpan);
}

unsigned int Span::longestSpan()
{
    if (_data.size() < 2) {
        std::string errStr = "no span found, span length = "
                             + std::to_string(_data.size()) + "!";
        throw std::logic_error(errStr);
    }
    else {
        return static_cast<unsigned int>(*this->_data.rbegin() - *this->_data.begin());
    }
}
