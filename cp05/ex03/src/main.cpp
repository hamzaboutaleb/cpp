#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *rrf;
    AForm *scf;
    AForm *ppf;
    AForm *unknownForm;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
    unknownForm = someRandomIntern.makeForm("unknown form", "Target");

    delete rrf;
    delete scf;
    delete ppf;
    delete unknownForm;

    return 0;
}