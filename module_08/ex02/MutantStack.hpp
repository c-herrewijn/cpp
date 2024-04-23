#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <list>
# include <stack>

template <typename T>
class MutantStack {
public:
    MutantStack();
    MutantStack(const MutantStack &obj);
    ~MutantStack();

    class iterator; // nested class

    MutantStack &operator=(const MutantStack &obj);
    const T &top() const;
    bool empty() const;
    size_t size() const;
    void push(const T &value);
    void pop();
    iterator begin(); // first element
    iterator end(); // past the last element
    // operator int() const { return 7; }
    operator std::stack<T>() const // conversion operator
    {
        std::stack<T> a; // todo return actual stack in correct order
        return a;
    }

private:
    std::list<T> _data;
};

template <typename T>
class MutantStack<T>::iterator {
public:
    iterator(T *ptr, MutantStack<T> &stack);
    iterator(const iterator &obj);
    ~iterator();

    T &operator*() const;
    iterator &operator++(); // pre-increment
    iterator operator++(int dummy); // post-increment
    iterator &operator--(); // pre-decrement
    iterator operator--(int dummy); // post-decrement
    bool operator!=(const iterator &rhs);
    bool operator==(const iterator &rhs);

private:
    T *_ptr;
    MutantStack<T> &_stack;
};

#include "MutantStack.tpp"

#endif
