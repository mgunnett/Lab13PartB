#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int dayOfWeek(int month, int day, int year);

int main() {
    char choice;
    int month, day, year;
    string monthName;

    cout << "Enter a date (month day year): ";
    while (true) {
        cin >> choice;
        if (toupper(choice) == 'Q') {
            break;
        }
        cin.unget(); // Put the character back into the input stream
        cin >> month >> day >> year;

        int weekday = dayOfWeek(month, day, year);

        string weekdays[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
        string months[] = { "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        cout << weekdays[weekday] << ", " << months[month-1] << " " << day << ", " << year <<"\n" << endl;

        cout << "Enter a date (month day year) or press 'Q' to quit: ";
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
    int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return h;
}