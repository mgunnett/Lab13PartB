#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

int dayOfWeek(int month, int day, int year);

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

int main() {
    string input;
    map<string, int> monthMap = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
        {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
        {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };

    cout << "Enter a month and a year or press 'Q' to quit: ";
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

        // Prepare the calendar output
        ostringstream calendarOutput;
        calendarOutput << monthName << " " << year << "\n";
        calendarOutput << "Su Mo Tu We Th Fr Sa\n";
        for (int i = 0; i < firstDay; ++i) {
            calendarOutput << "   ";
        }
        for (int day = 1; day <= daysInMonth; ++day) {
            calendarOutput << (day < 10 ? " " : "") << day << " ";
            if ((firstDay + day) % 7 == 0) {
                calendarOutput << "\n";
            }
        }
        calendarOutput << "\n";

        // Display the calendar
        cout << calendarOutput.str();

        // Create the output file name
        string outputFileName = monthName.substr(0, 3) + to_string(year) + ".txt";

        // Write the calendar to the output file
        ofstream outFile(outputFileName);
        if (outFile.is_open()) {
            outFile << calendarOutput.str();
            outFile.close();
            cout << "Calendar written to " << outputFileName << "\n";
        }
        else {
            cout << "Error opening file " << outputFileName << "\n";
        }

        cout << "\nEnter a month and a year or press 'Q' to quit: ";
    }

    return 0;
}