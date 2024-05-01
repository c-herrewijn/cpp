#include "PmergeMe.hpp"

bool Pair::operator<(Pair &rhs) const
{
    return (this->first < rhs.first);
}
bool Pair::operator>(Pair &rhs) const
{
    return (this->first > rhs.first);
}
