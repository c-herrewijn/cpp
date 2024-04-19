#ifndef SPAN_HPP
# define SPAN_HPP

# include <array>

class Span {
public:
    Span(unsigned int n);
    Span(const Span &obj);
    Span &operator=(const Span &obj);
    ~Span();

    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();

private:
    Span();
    unsigned int _maxSize;
    unsigned int _size;
    int *_data;
};

#endif
