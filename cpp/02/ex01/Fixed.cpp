#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float num) : value(roundf(num * (1 << this->bits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int num) : value(roundf(num * (1 << this->bits))) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->value = f.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

float Fixed::toFloat() const {
    return (static_cast<float>(this->value)) / (1 << this->bits);
}

int Fixed::toInt() const {
    return this->value / (1 << this->bits);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
