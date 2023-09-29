
#include "Date.h"
#include <iostream>

vector<std::string> Date::daysOfWeek = {"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};

Date::Date() : year(0), month(0), day(0), hours(0), minutes(0), seconds(0) {}

Date::Date(int y, int m, int d, int h, int min, int sec)
        : year(y), month(m), day(d), hours(h), minutes(min), seconds(sec) {}





bool Date::isDateValid(int year, int month, int day) {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return day <= 29; //високосний рік
    } else if (day >= daysInMonth[month - 1]) {
        return false;
    }

    return true;
}
bool Date::isDateValid(){
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return day <= 29; //високосний рік
    } else if (day >= daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

bool Date::isTimeValid() const {
    return (hours >= 0 && hours <= 24 && minutes >= 0 && minutes <= 60 && seconds >= 0 && seconds <= 60);
}
bool Date::isTimeValid(int hours, int minutes, int seconds) const {
    return (hours >= 0 && hours <= 24 && minutes >= 0 && minutes <= 60 && seconds >= 0 && seconds <= 60);
}
void Date::timeDifferencePrint()const{
    cout << "Time Difference: "<< year << "-" << month << "-" << day << " " << hours << ":" << minutes
    << ":" << seconds<<'\n';
}
Date Date::timeDifference(const Date& otherDate) const {
    int diffYears = year - otherDate.year;
    int diffMonths = month - otherDate.month;
    int diffDays = day - otherDate.day;
    int diffHours = hours - otherDate.hours;
    int diffMinutes = minutes - otherDate.minutes;
    int diffSeconds = seconds - otherDate.seconds;

    // Обробка випадку, коли різниця менша за 0
    while (diffSeconds < 0) {
        diffMinutes--;
        diffSeconds += 60;
    }
    while (diffMinutes < 0) {
        diffHours--;
        diffMinutes += 60;
    }
    while (diffHours < 0) {
        diffDays--;
        diffHours += 24;
    }
    while (diffDays < 0) {
        diffMonths--;
        int lastMonthDays = daysInMonth[(month - 2 + 12) % 12];
        diffDays += lastMonthDays;
    }
    while (diffMonths < 0) {
        diffYears--;
        diffMonths += 12;
    }

    // Створюємо та повертаємо новий об'єкт Date з різницею
    Date difference(diffYears, diffMonths, diffDays, diffHours, diffMinutes, diffSeconds);
    difference.timeDifferencePrint();
    return difference;
}

void Date::addTimeDifference(const Date& timeDiff) {
    year += timeDiff.year;
    month += timeDiff.month;
    day += timeDiff.day;
    hours += timeDiff.hours;
    minutes += timeDiff.minutes;
    seconds += timeDiff.seconds;

    // Обробка переповнень
    while (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    while (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    while (hours >= 24) {
        day += hours / 24;
        hours %= 24;
    }
    while (day > daysInMonth[month - 1]) {
        day -= daysInMonth[month - 1];
        month++;
        if (month > 12) {
            year++;
            month = 1;
        }
    }
}

void Date::subtractTimeDifference(const Date& timeDiff) {
    year -= timeDiff.year;
    month -= timeDiff.month;
    day -= timeDiff.day;
    hours -= timeDiff.hours;
    minutes -= timeDiff.minutes;
    seconds -= timeDiff.seconds;

    // Обробка випадку, коли значення стають від'ємними
    while (seconds < 0) {
        minutes--;
        seconds += 60;
    }
    while (minutes < 0) {
        hours--;
        minutes += 60;
    }
    while (hours < 0) {
        day--;
        hours += 24;
    }
    while (day < 1) {
        month--;
        if (month < 1) {
            year--;
            month = 12;
        }
        int lastMonthDays = daysInMonth[(month - 1 + 12) % 12];
        day += lastMonthDays;
    }
    while (month < 1) {
        year--;
        month += 12;
    }
}

int Date::getDayOfWeek() const {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int dayOfWeek = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return dayOfWeek;
}

int Date::getWeekOfMonth() const {
    int dayOfWeek = getDayOfWeek();
    int weekNumber = (day + dayOfWeek - 1) / 7 + 1;
    return weekNumber;
}

int Date::getWeekOfYear() const {
    int dayOfWeek = getDayOfWeek();
    int dayOfYear = 0;
    for (int i = 1; i < month; i++) {
        dayOfYear += daysInMonth[i - 1];
    }
    dayOfYear += day;

    int weekNumber = (dayOfYear + dayOfWeek - 1) / 7 + 1;
    return weekNumber;
}

void Date::setYear(int y) {
    if (y < 1) {
        // Обробка помилки встановлення року
    } else {
        year = y;
    }
}

void Date::setMonth(int m) {
    if (m < 1 || m > 12) {
        // Обробка помилки встановлення місяця
    } else {
        month = m;
    }
}

void Date::setDay(int d) {
    if (d < 1 || d > daysInMonth[month - 1]) {
        // Обробка помилки встановлення дня
    } else {
        day = d;
    }
}

void Date::setHours(int h) {
    if (h < 0 || h > 24) {
        // Обробка помилки встановлення годин
    } else {
        hours = h;
    }
}

void Date::setMinutes(int min) {
    if (min < 0 || min > 60) {
        // Обробка помилки встановлення хвилин
    } else {
        minutes = min;
    }
}

void Date::setSeconds(int sec) {
    if (sec < 0 || sec > 60) {
        // Обробка помилки встановлення секунд
    } else {
        seconds = sec;
    }
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getHours() const {
    return hours;
}

int Date::getMinutes() const {
    return minutes;
}

int Date::getSeconds() const {
    return seconds;
}

ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay() << "; "
       <<"week num in mon: " << date.getWeekOfMonth() << "; " // Виводимо номер тижня в місяці
       << Date::daysOfWeek[date.getDayOfWeek()] << "; " // Виводимо назву дня тижня
       << "Week num in year: " << date.getWeekOfYear() << ";"
       << " time: " << date.getHours() << ":" << date.getMinutes() << ":" << date.getSeconds() << endl;
    return os;
}

istream& operator>>(istream& in, Date& date){
    in >> date.year >> date.month >> date.day >> date.hours >> date.minutes >> date.seconds;
    return in;
}



