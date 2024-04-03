#include <string>
#include <iostream>
#include "iter.hpp"

template <typename T>
void printer(T &item)
{
    std::cout << item << std::endl;
}

template <typename T>
void doubler(T &item)
{
    item = item + item;
}

template <typename T>
void addQ(T &item)
{
    item = item + 'Q'; // note: Q has ascii value 81 (dec)
}

int main()
{
    std::string str_arr[3] = {"cat", "dog", "wolf"};
    int int_arr[4] = {2, 3, 5, 7};

    iter(str_arr, 3, printer);
    iter(str_arr, 3, doubler);
    iter(str_arr, 3, printer);
    iter(str_arr, 3, addQ);
    iter(str_arr, 3, printer);

    iter(int_arr, 4, printer);
    iter(int_arr, 4, doubler);
    iter(int_arr, 4, printer);
    iter(int_arr, 4, addQ);
    iter(int_arr, 4, printer);
}
