#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class Pair {
public:
    unsigned int first;
    unsigned int second;

    bool operator<(Pair &rhs) const;
    bool operator>(Pair &rhs) const;
};

#endif
