#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 150);

    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Bender");
    PresidentialPardonForm pardonForm("Marvin");

    bob.signForm(shrubberyForm);
    bob.executeForm(shrubberyForm);

    bob.signForm(robotomyForm);
    bob.executeForm(robotomyForm);

    bob.signForm(pardonForm);
    bob.executeForm(pardonForm);

    alice.signForm(shrubberyForm);
    alice.executeForm(shrubberyForm);

    return 0;
}