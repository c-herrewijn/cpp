#ifndef BUREAUCRAT_H
# define  BUREAUCRAT_H

#include <string>

class  Bureaucrat {
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &obj);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;

private:
    int grade;
    const std::string name;
    Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
