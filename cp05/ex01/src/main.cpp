#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        Form taxForm("Tax Form", 30, 20);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;

        for (int i = 0; i < 25; ++i)
            bob.incrementGrade();

        std::cout << bob << std::endl;
        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}