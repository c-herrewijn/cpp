#include <string>
#include <iostream>
#include "iter.hpp"

#define ANSI_GREEN "\x1b[32m"
#define ANSI_RESET "\x1b[0m"

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
    const int const_int_arr[4] = {20, 30, 50, 70};

    std::cout << ANSI_GREEN << "testing string:\n" << ANSI_RESET;
    iter(str_arr, 3, printer);
    iter(str_arr, 3, doubler);
    iter(str_arr, 3, printer);
    iter(str_arr, 3, addQ);
    iter(str_arr, 3, printer);

    std::cout << ANSI_GREEN << "\ntesting int:\n" << ANSI_RESET;
    iter(int_arr, 4, printer);
    iter(int_arr, 4, doubler);
    iter(int_arr, 4, printer);
    iter(int_arr, 4, addQ);
    iter(int_arr, 4, printer);

    // check for const int
    std::cout << ANSI_GREEN << "\ntesting const int printer (different inputs):\n" << ANSI_RESET;
    iter(int_arr, 4, printer<const int>); // int array printed with const int printer
    iter(const_int_arr, 4, printer);
}
