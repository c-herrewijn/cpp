#include <set>
#include <stdexcept>

#include "Span.hpp"

Span::Span() : _maxSize(0), _size(0), _data(std::multiset<int>()) {}

Span::Span(unsigned int n) : _maxSize(n), _size(0), _data(std::multiset<int>()) {}

Span::Span(const Span &obj) :
    _maxSize(obj._maxSize),
    _size(obj._size),
    _data(obj._data)
{}

Span::~Span() {}

Span &Span::operator=(const Span &obj) {
    this->_maxSize = obj._maxSize;
    this->_size = obj._size;
    this->_data = obj._data;
    return *this;
}

void Span::addNumber(int n) {
    if (this->_size < this->_maxSize) {
        this->_data.emplace(n);
        this->_size++;
    }
    else {
        throw std::range_error("no space in span");
    }
}

unsigned int Span::shortestSpan() {
    return 42; // dummy
}

unsigned int Span::longestSpan() {
    return 42; // dummy
}
