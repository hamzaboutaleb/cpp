
#include <Fixed.hpp>
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(const int v)
{
    std::cout << "setRawBits member function called" << std::endl;
    value = v;
}