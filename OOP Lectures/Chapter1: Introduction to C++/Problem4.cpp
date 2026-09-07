#include <iostream>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

    bool IsLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int GetDaysInMonth() const {
        if (month == 2) {
            return IsLeapYear() ? 29 : 28;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        return 31;
    }

    string GetDayOfWeek() const {
        int y = year;
        int m = month;
        int d = day;
        static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        y -= m < 3;
        int dow = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
        
        string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return days[dow];
    }

    Date& operator++() {
        day++;
        if (day > GetDaysInMonth()) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    Date& operator--() {
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = GetDaysInMonth();
        }
        return *this;
    }

    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Date& other) const {
        return other < *this; 
    }
};

istream& operator>>(istream& is, Date& d) {
    cout << "Enter day: "; is >> d.day;
    cout << "Enter month: "; is >> d.month;
    cout << "Enter year: "; is >> d.year;
    return is;
}

ostream& operator<<(ostream& os, const Date& d) {
    os << (d.day < 10 ? "0" : "") << d.day << "/"
       << (d.month < 10 ? "0" : "") << d.month << "/"
       << d.year;
    return os;
}

int main() {
    Date d1, d2;

    cout << "--- INPUT DATE 1 ---\n";
    cin >> d1;
    cout << "--- INPUT DATE 2 ---\n";
    cin >> d2;

    cout << "\nDate 1: " << d1 << " (" << d1.GetDayOfWeek() << ")" << endl;
    cout << "Date 2: " << d2 << " (" << d2.GetDayOfWeek() << ")" << endl;

    cout << "\n--- INCREMENT & DECREMENT (Date 1) ---" << endl;
    Date d1_copy = d1;
    d1_copy++;
    cout << "Date 1 after ++ : " << d1_copy << endl;
    
    d1_copy = d1;
    d1_copy--;
    cout << "Date 1 after -- : " << d1_copy << endl;

    cout << "\n--- COMPARISON ---" << endl;
    if (d1 == d2) cout << "Date 1 == Date 2" << endl;
    if (d1 != d2) cout << "Date 1 != Date 2" << endl;
    if (d1 < d2)  cout << "Date 1 is BEFORE Date 2 (<)" << endl;
    if (d1 > d2)  cout << "Date 1 is AFTER Date 2 (>)" << endl;

    return 0;
}