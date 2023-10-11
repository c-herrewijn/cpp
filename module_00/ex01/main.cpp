#include <PhoneBook.h>

#include <iostream>
#include <string>

int main()
{
    PhoneBook book;
    std::string input;

    while (true) {
        std::cout << "Enter command: ADD, SEARCH or EXIT" << std::endl << "> ";
        if (!std::getline(std::cin, input) || std::cin.eof()) {
            break;
        }
        if (input.compare("ADD") == 0 || input.compare("add") == 0) {
            if (book.user_add_contact() == false) {
                break;
            }
        }
        else if (input.compare("SEARCH") == 0 || input.compare("search") == 0) {
            if (book.search_contact() == false) {
                break;
            }
        }
        else if (input.compare("EXIT") == 0 || input.compare("exit") == 0) {
            break;
        }
        else {
            std::cout << "Invalid input!" << std::endl;
        }
    }
    return (0);
}
