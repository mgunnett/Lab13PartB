#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int dayOfWeek(int month, int day, int year);

int main() {
    string input;
    map<string, int> monthMap = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
        {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
        {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };

    cout << "Enter a month and a year or press 'Q' to quit: \n";
    while (getline(cin, input)) {
        if (toupper(input[0]) == 'Q') {
            break;
        }

        string monthName;
        int year;
        istringstream ss(input);
        ss >> monthName >> year;

        // Check if the month name is valid
        if (monthMap.find(monthName) == monthMap.end()) {
            cout << "Invalid month name. Please try again.\n";
            continue;
        }

        int month = monthMap[monthName];
        int firstDay = dayOfWeek(month, 1, year);
        int daysInMonth = (month == 2) ? ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28) :
            (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;

        // Print the month and year
        cout << "\n" << monthName << " " << year << "\n";
        cout << "Su Mo Tu We Th Fr Sa\n";
        for (int i = 0; i < firstDay; ++i) {
            cout << "   ";
        }
        for (int day = 1; day <= daysInMonth; ++day) {
            cout << (day < 10 ? " " : "") << day << " ";
            if ((firstDay + day) % 7 == 0) {
                cout << "\n";
            }
        }
        cout << "\n\nEnter a month and a year (e.g., November 2023) or press 'Q' to quit: ";
    }

    return 0;
}

/**
 * dayOfWeek - Computes the weekday of a given date.
 * @param year the year
 * @param month the month (1 = January ... 12 = December)
 * @param day the day of the month
 * @return the weekday (0 = Saturday ... 6 = Friday)
 */
int dayOfWeek(int month, int day, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    return (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
}