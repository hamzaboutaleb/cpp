#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade())
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << target << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
}