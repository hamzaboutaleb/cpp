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

bool Fixed::operator>(const Fixed &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed &Fixed::operator--(void)
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->value--;
    return temp;
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}