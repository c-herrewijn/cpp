#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "AForm.h"
#include <iostream>
#include <exception>

#define  ANSI_RED  "\x1b[31m"
#define  ANSI_GREEN  "\x1b[32m"
#define  ANSI_RESET  "\x1b[0m"
#define  ANSI_GREY  "\x1b[38;5;241m"

template <class T>
void testHappy(void)
{
    std::cout << ANSI_GREEN << T::formType << ": happy flow:" << std::endl
              << ANSI_RESET;
    Bureaucrat queen("Queen Maxima", 5);
    Bureaucrat royalAssistent("Royal Assistent", 25);
    Bureaucrat powerlessPeter("Powerless Peter", 150);

    T formLuke("Lucky Luke");
    std::cout << ANSI_GREY << formLuke << std::endl << ANSI_RESET;

    royalAssistent.signForm(formLuke);
    std::cout << ANSI_GREY << formLuke << std::endl << ANSI_RESET;

    queen.executeForm(formLuke);
    std::cout << ANSI_GREY << formLuke << std::endl << ANSI_RESET;
}

template <class T>
void testError(void)
{
    std::cout << ANSI_RED << T::formType << ": error cases:" << std::endl
              << ANSI_RESET;

    Bureaucrat queen("Queen Maxima", 5);
    Bureaucrat royalAssistent("Royal Assistent", 25);
    Bureaucrat powerlessPeter("Powerless Peter", 150);

    T formLeo("Unlucky Leo");
    std::cout << ANSI_GREY << formLeo << std::endl << ANSI_RESET;
    powerlessPeter.signForm(formLeo);
    std::cout << ANSI_GREY << formLeo << std::endl << ANSI_RESET;

    // execute error (Unsigned Form)
    queen.executeForm(formLeo);
    std::cout << ANSI_GREY << formLeo << std::endl << ANSI_RESET;

    // execute error (Grade Too Low )
    royalAssistent.signForm(formLeo);
    std::cout << ANSI_GREY << formLeo << std::endl << ANSI_RESET;
    royalAssistent.executeForm(formLeo);
    std::cout << ANSI_GREY << formLeo << std::endl << ANSI_RESET;
}

int main()
{
    testHappy<PresidentialPardonForm>();
    testError<PresidentialPardonForm>();
}
