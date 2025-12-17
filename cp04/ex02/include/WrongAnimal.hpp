#ifndef WORNGANIMAL_HPP
#define WORNGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);
    ~WrongAnimal();

    const std::string getType() const;
    void setType(std::string type);
    void makeSound() const;
};

#endif