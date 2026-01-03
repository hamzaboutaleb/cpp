#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}
AForm::~AForm() {}
AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      signGrade(other.signGrade), executeGrade(other.executeGrade) {}
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecuteGrade() const
{
    return executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
    out << "AForm Name: " << Aform.getName() << ", Signed: " << (Aform.getIsSigned() ? "Yes" : "No")
        << ", Sign Grade: " << Aform.getSignGrade() << ", Execute Grade: " << Aform.getExecuteGrade();
    return out;
}