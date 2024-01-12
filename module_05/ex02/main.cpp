#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include <iostream>
#include <exception>

#define  ANSI_RED  "\x1b[31m"
#define  ANSI_GREEN  "\x1b[32m"
#define  ANSI_RESET  "\x1b[0m"
#define  ANSI_GREY  "\x1b[38;5;241m"

int main()
{
    // PresidentialPardonForm: happy flow
    std::cout << ANSI_GREEN << "PresidentialPardonForm: happy flow:" << std::endl
              << ANSI_RESET;

    Bureaucrat queen("Queen Maxima", 5);
    Bureaucrat royalAssistent("Royal Assistent", 25);
    Bureaucrat powerlessPeter("Powerless Peter", 150);

    PresidentialPardonForm pardonformLuke("Lucky Luke");
    std::cout << ANSI_GREY << pardonformLuke << std::endl << ANSI_RESET;

    royalAssistent.signForm(pardonformLuke);
    std::cout << ANSI_GREY << pardonformLuke << std::endl << ANSI_RESET;

    queen.executeForm(pardonformLuke);
    std::cout << ANSI_GREY << pardonformLuke << std::endl << ANSI_RESET;

    // PresidentialPardonForm: error cases
    // sign error
    std::cout << ANSI_RED << "PresidentialPardonForm: error cases:" << std::endl
              << ANSI_RESET;
    PresidentialPardonForm pardonformLeo("Unlucky Leo");
    std::cout << ANSI_GREY << pardonformLeo << std::endl << ANSI_RESET;
    powerlessPeter.signForm(pardonformLeo);
    std::cout << ANSI_GREY << pardonformLeo << std::endl << ANSI_RESET;

    // PresidentialPardonForm: execute error (Unsigned Form)
    queen.executeForm(pardonformLeo);
    std::cout << ANSI_GREY << pardonformLeo << std::endl << ANSI_RESET;

    // PresidentialPardonForm: execute error (Grade Too Low )
    royalAssistent.signForm(pardonformLeo);
    std::cout << ANSI_GREY << pardonformLeo << std::endl << ANSI_RESET;
    royalAssistent.executeForm(pardonformLeo);
    std::cout << ANSI_GREY << pardonformLeo << std::endl << ANSI_RESET;
}
