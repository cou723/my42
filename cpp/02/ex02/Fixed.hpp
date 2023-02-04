#ifndef B811E7B6_4170_4CA0_ABF7_3DB2BBA76337_H
#define B811E7B6_4170_4CA0_ABF7_3DB2BBA76337_H

#include <iostream>
class Fixed {
   private:
    int value;
    static const int bits = 8;

   public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed& fixed);
    ~Fixed();

    Fixed& operator=(const Fixed& fixed);

    bool operator<(const Fixed& fixed);
    bool operator>(const Fixed& fixed);
    bool operator>=(const Fixed& fixed);
    bool operator<=(const Fixed& fixed);
    bool operator==(const Fixed& fixed);
    bool operator!=(const Fixed& fixed);

    Fixed operator+(const Fixed& fixed);
    Fixed operator-(const Fixed& fixed);
    Fixed operator*(const Fixed& fixed);
    Fixed operator/(const Fixed& fixed);

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    static Fixed& max(Fixed& a, Fixed& b);
    static Fixed& max(const Fixed& a, const Fixed& b);
    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& min(const Fixed& a, const Fixed& b);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif /* B811E7B6_4170_4CA0_ABF7_3DB2BBA76337_H */
