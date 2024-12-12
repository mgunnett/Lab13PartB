#include <iostream>
#include <cctype>

using namespace std;

bool isLeapYear(int year);

int main() {
    char choice;
    int year;

    cout << "Enter a year: ";
    while (true) {
        cin >> choice;
        if (toupper(choice) == 'Q') {
            break; 
        }
        cin.unget(); // Put the character back into the input stream
        cin >> year;

        if (isLeapYear(year)) {
            cout << year << " is a leap year.\n" << endl;
        }
        else {
            cout << year << " is not a leap year.\n" << endl;
        }

        cout << "Enter a year or press 'Q' to quit: ";
    }

    return 0;
}

bool isLeapYear(int year) {
    return (year >= 1582) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}


