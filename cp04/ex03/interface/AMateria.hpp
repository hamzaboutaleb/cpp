#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    AMateria(const std::string &type);
    virtual ~AMateria();

    const std::string &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target) = 0;
};

#endif