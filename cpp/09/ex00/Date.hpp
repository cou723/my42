#ifndef DATE_H
#define DATE_H
#include <string>

#include "utils.hpp"
class Date {
   private:
    std::string _date;
    int _year;
    int _month;
    int _day;

   public:
    Date();
    Date(std::string date);
    Date(const Date& date);
    ~Date();
    Date& operator=(const Date& date);

    std::string getDate() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getLastMonth() const;
    std::string getYesterday() const;
    bool operator<(const Date& date) const;
    bool operator>(const Date& date) const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif /* DATE_H */
