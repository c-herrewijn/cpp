#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <list>

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
    iterator begin();
    iterator end();


private:
    std::list<T> _data;
};

template <typename T>
class MutantStack<T>::iterator {
public:
    iterator(T *ptr); // constructor
    T &operator*() const;

private:
    T *_ptr;
};

#include "MutantStack.tpp"

#endif
