
#include <Fixed.hpp>
#include <iostream>
#include <cmath>

Fixed::Fixed(int v)
{
    std::cout << "Int constructor called" << std::endl;
    value = v << fractionalBits;
}

Fixed::Fixed(float f)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(f * (1 << fractionalBits));
}

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
    value = other.value;
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

float Fixed::toFloat(void) const
{
    return (float)this->value / (float)(1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->value >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}