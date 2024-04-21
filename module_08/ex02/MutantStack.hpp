#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack {
public:
    MutantStack();
    MutantStack(const MutantStack &obj);
    ~MutantStack();

    MutantStack &operator=(const MutantStack &obj);
    T &top() const;
    bool empty() const;
    size_t size() const;
    void push( const T &value );
    void pop();
    class iterator {
        T *begin(); // getter
        T *end(); // getter
    };

private:
    std::stack<T> _data;
};

#include "MutantStack.tpp"

#endif
