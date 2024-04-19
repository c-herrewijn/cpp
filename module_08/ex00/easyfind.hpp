#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

/*
returns iterator to the first element in the container that matches valueToFind
returns iterator.end() if valueToFind is not in the container
iterator.end() is the position directly after the last element in the vector
*/
template <typename T>
typename T::iterator easyfind(T &container, int valueToFind)
{
    return std::find(container.begin(), container.end(), valueToFind);
}

#endif
