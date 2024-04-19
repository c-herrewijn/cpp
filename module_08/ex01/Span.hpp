#ifndef SPAN_HPP
# define SPAN_HPP

# include <array>
# include <set>

class Span {
public:
    Span();
    Span(unsigned int n);
    Span(const Span &obj);
    Span &operator=(const Span &obj);
    ~Span();

    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();

private:
    unsigned int _maxSize;
    unsigned int _size;
    std::multiset<int> _data;
};

#endif
