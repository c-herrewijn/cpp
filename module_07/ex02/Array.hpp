#ifndef ARRAY_H
# define ARRAY_H

template <class T>
class Array {
public:
    Array<T>();
    Array<T>(unsigned int n);
    ~Array();
    Array<T>(const Array<T> &object);
    Array<T> &operator=(const Array<T> &object);
    T &operator[](size_t index) const;
    size_t size(void) const;

private:
    const size_t _size;
    T *const _data;
};

#include "Array.tpp"

#endif
