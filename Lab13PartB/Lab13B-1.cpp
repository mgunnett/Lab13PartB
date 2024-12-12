#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int daysInMonth(int month, int year);

int main() {
    char choice;
    int month, year;
    string monthName;
    

    cout << "Enter a month and a year: ";
    while (true) {
        cin >> choice;
        if (toupper(choice) == 'Q') {
            break;
        }
        cin.unget(); // Put the character back into the input stream
        cin >> month >> year;

        if (month == 1) {
            monthName = "January";
        }
        if (month == 2) {
            monthName = "Feburary";
        }
        if (month == 3) {
            monthName = "March";
        }
        if (month == 4) {
            monthName = "April";
        }
        if (month == 5) {
            monthName = "May";
        }
        if (month == 6) {
            monthName = "June";
        }
        if (month == 7) {
            monthName = "July";
        }
        if (month == 8) {
            monthName = "August";
        }
        if (month == 9) {
            monthName = "September";
        }
        if (month == 10) {
            monthName = "October";
        }
        if (month == 11) {
            monthName = "November";
        }
        if (month == 3) {
            monthName = "December";
        }

        int days = daysInMonth(month, year);
        cout << monthName << " " << year << " has " << days << " days.\n" << endl;

        cout << "Enter a month and a year or press 'Q' to quit: ";
    }

    return 0;
}
/**
 * daysInMonth – determines the number of days in a specified month
 * @param month the month; expected to be in the range [1..12]
 * @param year the year; expected to be >= 1582
 * @return either 28, 29, 30, or 31, based on month and (leap) year
 */
int daysInMonth(int month, int year) {
    if (month == 2) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

