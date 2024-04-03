#ifndef ITER
# define ITER

#include <cstddef>

template <typename T>
void iter(T arr[], size_t len, void (*f)(T &item))
{
    for (size_t i=0; i<len; i++) {
        f(arr[i]);
    }
}

#endif
