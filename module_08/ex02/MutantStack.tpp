#include <list>
#include <stdint.h>
#include <vector>

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &obj)
{
    *this = obj;
}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &obj)
{
    this->_data = obj.data;
    return *this;
}

template<typename T>
const T &MutantStack<T>::top() const
{
    return (this->_data.front());
}

template<typename T>
bool MutantStack<T>::empty() const
{
    return (this->_data.empty());
}

template<typename T>
size_t MutantStack<T>::size() const
{
    return (this->_data.size());
}

template<typename T>
void MutantStack<T>::push(const T &value)
{
    this->_data.push_front(value);
}

template<typename T>
void MutantStack<T>::pop()
{
    this->_data.pop_front();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    MutantStack<T>::iterator it(&(this->_data.front()), *this);
    return it;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    MutantStack<T>::iterator it(&(this->_data.back()), *this);
    return (++it); // end is after last element
}

template<typename T>
MutantStack<T>::operator std::stack<T>()
{
    std::vector<T> temp;
    std::stack<T> st;
    for (iterator it=(this->begin()); it!=(this->end()); it++)
    {
        temp.push_back(*it);
    }
    if (temp.size() > 0) {
        for (int i=temp.size()-1; i>=0; i--)
        {
            st.push(temp[i]);
        }
    }
    return st;
}


// ITERATOR //

template<typename T>
MutantStack<T>::iterator::iterator(T *ptr, MutantStack<T> &stack) :
    _ptr(ptr),
    _stack(stack)
{}

template<typename T>
MutantStack<T>::iterator::iterator(const MutantStack<T>::iterator &obj) :
    _ptr(obj._ptr),
    _stack(obj._stack)
{}

template<typename T>
MutantStack<T>::iterator::~iterator() {}

template<typename T>
T &MutantStack<T>::iterator::operator*() const
{
    return (*(this->_ptr));
}

template<typename T>
bool MutantStack<T>::iterator::operator!=(const MutantStack<T>::iterator &rhs)
{
    return (this->_ptr != rhs._ptr);
}

template<typename T>
bool MutantStack<T>::iterator::operator==(const MutantStack<T>::iterator &rhs)
{
    return (this->_ptr == rhs._ptr);
}

// pre-increment
template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++()
{
    std::list<T> &lst = this->_stack._data;
    for (typename std::list<T>::iterator it=lst.begin(); it != lst.end(); it++) {
        if (&*it == this->_ptr) {
            this->_ptr = &*(++it);
        }
    }
    return (*this);
}

// post-increment
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int dummy)
{
    (void)dummy;
    iterator orig(*this);
    std::list<T> &lst = this->_stack._data;
    for (typename std::list<T>::iterator it=lst.begin(); it != lst.end(); it++) {
        if (&*it == this->_ptr) {
            this->_ptr = &*(++it);
        }
    }
    return (orig);
}

// pre-decrement
template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--()
{
    std::list<T> &lst = this->_stack._data;
    for (typename std::list<T>::iterator it=lst.begin(); it != lst.end(); it++) {
        if (&*it == this->_ptr) {
            this->_ptr = &*(--it);
        }
    }
    return (*this);
}

// post-decrement
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int dummy)
{
    (void)dummy;
    iterator orig(*this);
    std::list<T> &lst = this->_stack._data;
    for (typename std::list<T>::iterator it=lst.begin(); it != lst.end(); it++) {
        if (&*it == this->_ptr) {
            this->_ptr = &*(--it);
        }
    }
    return (orig);
}
