
#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria() : type("default") {}

AMateria::AMateria(const AMateria &other) : type(other.type) {}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria() {}

const std::string &AMateria::getType() const
{
    return this->type;
}