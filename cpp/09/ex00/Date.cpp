#include "Date.hpp"
#ifdef TEST
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#endif
#include <stdexcept>
#include <string>
#include <vector>

int toYear(std::string year) {
    int y = myStoi(year);
    if (y < 0) throw std::runtime_error("Invalid year");
    return y;
}

int toMonth(std::string month) {
    int m = myStoi(month);
    if (m < 1 || m > 12) throw std::runtime_error("Invalid month");
    return m;
}

int toDay(int month, std::string day) {
    int d = myStoi(day);
    if (d < 1 || d > 31) throw std::runtime_error("Invalid day");
    if (month == 2) {
        if (d > 29) throw std::runtime_error("Invalid day");
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (d > 30) throw std::runtime_error("Invalid day");
    }
    return d;
}

Date::Date() {}

Date::Date(std::string date) : _date(date) {
    const char* str = date.c_str();
    std::vector<std::string> tokens;
    tokens.push_back(std::string(""));
    while (*str != '\0') {
        if (*str == '-') {
            tokens.push_back(std::string(""));
            str++;
            continue;
        }
        tokens.back() += std::string(str, 1);
        str++;
    }
    if (tokens.size() != 3) throw std::runtime_error("Invalid date format");
    _year = toYear(tokens[0]);
    _month = toMonth(tokens[1]);
    _day = toDay(myStoi(tokens[1]), tokens[2]);
};

Date::Date(const Date& date)
    : _date(date._date),
      _year(date._year),
      _month(date._month),
      _day(date._day){};
Date::~Date(){};

Date& Date::operator=(const Date& date) {
    if (this != &date) {
        _date = date._date;
        _year = date._year;
        _month = date._month;
        _day = date._day;
    }
    return *this;
}

std::string Date::getDate() const { return _date; }

int Date::getDay() const { return _day; }

int Date::getMonth() const { return _month; }

int Date::getYear() const { return _year; }

int Date::getLastMonth() const {
    return this->getMonth() - 1 == 0 ? 12 : this->getMonth() - 1;
}

std::string Date::getYesterday() const {
    if (this->getDay() != 1)
        return _date.substr(0, _date.rfind("-") + 1) +
               toFormatString(this->getDay() - 1);
    int prev_day;
    switch (this->getLastMonth()) {
        case 2:
            if (this->getYear() % 4 == 0 &&
                (this->getYear() % 100 != 0 || this->getYear() % 400 == 0)) {
                prev_day = 29;
            } else {
                prev_day = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            prev_day = 30;
            break;
        default:
            prev_day = 31;
    }
    int isYearDecrement = 0;
    if (getLastMonth() == 12 && prev_day == 31) isYearDecrement = 1;
    return myToString(this->getYear() - isYearDecrement) + "-" +
           toFormatString(this->getLastMonth()) + "-" +
           toFormatString(prev_day);
}

bool Date::operator<(const Date& date) const {
    if (this->getYear() < date.getYear())
        return true;
    else if (this->getYear() == date.getYear()) {
        if (this->getMonth() < date.getMonth())
            return true;
        else if (this->getMonth() == date.getMonth()) {
            if (this->getDay() < date.getDay()) return true;
        }
    }
    return false;
}

bool Date::operator>(const Date& date) const { return !(*this < date); }

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.getDate();
    return os;
}

#ifdef TEST
TEST_CASE("Date Unit Test") {
    CHECK_THROWS_AS(Date(""), std::runtime_error);
    CHECK_THROWS_AS(Date("invalid"), std::runtime_error);
    CHECK_THROWS_AS(Date("----"), std::runtime_error);
    CHECK_THROWS_AS(Date("test-te-te"), std::runtime_error);
    CHECK_THROWS_AS(Date("-100-12-1"), std::runtime_error);
    CHECK_THROWS_AS(Date("2022-13-29"), std::runtime_error);
    CHECK_THROWS_AS(Date("2022-01-0"), std::runtime_error);
    CHECK(Date("2022-01-01").getMonth() == 1);
    CHECK(Date("2022-01-01").getDay() == 1);
    CHECK(Date("2022-01-01").getLastMonth() == 12);
    CHECK(Date("2022-02-01").getLastMonth() == 1);
    CHECK(Date("2022-01-02").getYesterday() == "2022-01-01");
    CHECK(Date("2022-02-01").getYesterday() == "2022-01-31");
    CHECK(Date("2022-01-01").getYesterday() == "2021-12-31");
    CHECK(Date("2011-01-03").getYesterday() == "2011-01-02");
}
#endif