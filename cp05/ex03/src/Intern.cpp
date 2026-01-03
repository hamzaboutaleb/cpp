#include "Intern.hpp"

static AForm *makePresident(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}
Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    AForm *(*formCreators[])(const std::string &) = {
        makeShrubbery,
        makeRobot,
        makePresident};

    for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Error: Form name \"" << formName << "\" is not recognized." << std::endl;
    return NULL;
}