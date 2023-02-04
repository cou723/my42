#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float num) : value(roundf(num * (1 << this->bits))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int num) : value(roundf(num * (1 << this->bits))) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed& Fixed::operator=(const Fixed& f) {
    // std::cout << "Copy assignment operator called" << std::endl;
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
    // std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed& fixed) {
    return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed& fixed) {
    return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed& fixed) {
    return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed& fixed) {
    return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed& fixed) {
    return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed& fixed) {
    return this->getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed& fixed) {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) {
    if (fixed.getRawBits() == 0)
        throw std::overflow_error("Zero division detected.");
    return Fixed(this->toFloat() / fixed.toFloat());
}

// ++pre
Fixed& Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

// post++ 加算した奴は返さなくてよい
// コピーコンストラクタを使っている都合上コピーコンストラクタが膨大であればあるほど後置インクリメントは前置インクリメントと比べて遅くなりがち
Fixed Fixed::operator++(int) {
    Fixed f(*this);                            // Fixedのコピー
    this->setRawBits(this->getRawBits() + 1);  // 元をインクリメント
    return f;  // (インクリメントされてないFexed)のコピーを返す
}

Fixed& Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed f(*this);
    this->setRawBits(this->getRawBits() - 1);
    return f;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.getRawBits() > b.getRawBits()) ? (Fixed&)a : (Fixed&)b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.getRawBits() < b.getRawBits()) ? (Fixed&)a : (Fixed&)b;
}
