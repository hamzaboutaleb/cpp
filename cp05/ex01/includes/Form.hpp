#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string name;
    bool isSigned;
    int signGrade;
    int executeGrade;

public:
    Form(const std::string &name, int signGrade, int executeGrade);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif