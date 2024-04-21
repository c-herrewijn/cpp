#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <vector>

class Span {
public:
    Span();
    Span(unsigned int n);
    Span(const Span &obj);
    Span &operator=(const Span &obj);
    ~Span();

    void addNumber(int n);
    void insertFromVector(std::vector<int> &vect);
    unsigned int shortestSpan();
    unsigned int longestSpan();

private:
    unsigned int _maxSize;
    unsigned int _size;
    std::multiset<int> _data;
};

#endif
