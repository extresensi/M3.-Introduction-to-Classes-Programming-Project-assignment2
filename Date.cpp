#include "Date.h"
#include <iostream>
#include <sstream>
using namespace std;

// Helper: validate date
bool Date::isValidDate(int m, int d, int y) const {
    if (m < 1 || m > 12) return false;
    if (y < 1) return false;

    int maxDay = lastDay(m, y);
    return (d >= 1 && d <= maxDay);
}

// Constructor
Date::Date(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
    } else {
        month = 1;
        day = 1;
        year = 1900;
    }
}

// Mutator
void Date::setDate(int m, int d, int y) {
    if (isValidDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
    } else {
        month = 1;
        day = 1;
        year = 1900;
    }
}

// Leap year (object version)
bool Date::isLeapYear() const {
    return isLeapYear(year);
}

// Leap year (explicit year)
bool Date::isLeapYear(int y) const {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

// Last day of current month
int Date::lastDay() const {
    return lastDay(month, year);
}

// Last day of given month/year
int Date::lastDay(int m, int y) const {
    switch (m) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(y) ? 29 : 28;
        default:
            return 31;
    }
}

// Output formats
string Date::toNumericString() const {
    stringstream ss;
    ss << month << "/" << day << "/" << year;
    return ss.str();
}

string Date::toLongString() const {
    static const string names[12] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };
    stringstream ss;
    ss << names[month - 1] << " " << day << ", " << year;
    return ss.str();
}

string Date::toInternationalString() const {
    static const string names[12] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };
    stringstream ss;
    ss << day << " " << names[month - 1] << " " << year;
    return ss.str();
}
