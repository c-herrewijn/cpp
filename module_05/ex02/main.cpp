#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include <iostream>
#include <exception>

int main()
{
    // PresidentialPardonForm: happy flow
    std::cout << "PresidentialPardonForm: happy flow:" << std::endl;

    Bureaucrat queen("Queen Maxima", 5);
    Bureaucrat royalAssistent("Royal Assistent", 25);

    PresidentialPardonForm pardonform("Lucky Luke");
    std::cout << pardonform << std::endl;

    std::cout << "signing form..." << std::endl;
    royalAssistent.signForm(pardonform);
    std::cout << pardonform << std::endl;

    std::cout << "executing form..." << std::endl;
    queen.executeForm(pardonform);
    std::cout << pardonform << std::endl;

    // PresidentialPardonForm: sign error

    // PresidentialPardonForm: execute error (Unsigned Form)

    // PresidentialPardonForm: execute error (Grade Too Low )
}
