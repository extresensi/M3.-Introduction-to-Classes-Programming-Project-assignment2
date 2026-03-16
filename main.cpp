#include <iostream>
#include "Date.h"
using namespace std;

void printDateInfo(const Date& d) {
    cout << "Numeric:        " << d.toNumericString() << endl;
    cout << "Long:           " << d.toLongString() << endl;
    cout << "International:  " << d.toInternationalString() << endl;
    cout << endl;
}

int main() {

    cout << "===== DEFAULT CONSTRUCTOR TEST =====" << endl;
    Date d1;
    printDateInfo(d1);

    cout << "===== VALID PARAMETERIZED CONSTRUCTOR TEST =====" << endl;
    Date d2(12, 25, 2021);
    printDateInfo(d2);

    cout << "===== INVALID PARAMETERIZED CONSTRUCTOR TEST =====" << endl;
    Date d3(13, 40, -5);
    printDateInfo(d3);

    cout << "===== VALID setDate() TEST =====" << endl;
    d1.setDate(2, 14, 2022);
    printDateInfo(d1);

    cout << "===== INVALID setDate() TEST =====" << endl;
    d1.setDate(2, 30, 2022);
    printDateInfo(d1);

    cout << "===== LEAP YEAR TESTS =====" << endl;
    cout << "2024 leap? " << d1.isLeapYear(2024) << endl;
    cout << "2023 leap? " << d1.isLeapYear(2023) << endl;
    cout << "1900 leap? " << d1.isLeapYear(1900) << endl;
    cout << "2000 leap? " << d1.isLeapYear(2000) << endl;
    cout << endl;

    cout << "===== LAST DAY OF MONTH TESTS =====" << endl;
    cout << "Jan 2021: " << d1.lastDay(1, 2021) << endl;
    cout << "Apr 2021: " << d1.lastDay(4, 2021) << endl;
    cout << "Feb 2023: " << d1.lastDay(2, 2023) << endl;
    cout << "Feb 2024: " << d1.lastDay(2, 2024) << endl;
    cout << endl;

    cout << "===== EDGE CASE VALIDATION TESTS =====" << endl;
    Date e1(4, 30, 2022);
    Date e2(4, 31, 2022);
    printDateInfo(e1);
    printDateInfo(e2);

    return 0;
}
