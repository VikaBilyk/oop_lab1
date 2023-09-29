//
// Created by Вікторія Білик on 24.09.2023.
//



#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
    string description;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static std::vector<std::string> daysOfWeek;



public:
    Date() : year(0), month(0), day(0), hours(0), minutes(0), seconds(0), description("") {}

    Date(int y, int m, int d, int h, int min, int sec, string des)
            : year(y), month(m), day(d), hours(h), minutes(min), seconds(sec), description(des) {}

    bool isDateValid(int year, int month, int day) {
        if (year < 1 || month < 1 || month > 12 || day < 1)
            return false;

        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            cout << "рік високосний";
            return day <= 29;
        } else if (day >= daysInMonth[month - 1]) {
            cout << "У данному місяці: " << daysInMonth[month - 1];
            return false;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay() << " ";
        os << "Week " << date.getWeekOfMonth() << " "; // Виводимо номер тижня в місяці

        os << daysOfWeek[date.getDayOfWeek()] << " "; // Виводимо назву дня тижня
        os << date.getHours() << ":" << date.getMinutes() << ":" << date.getSeconds();
        return os;
    }




    bool isTimeValid() const {
        return (hours >= 0 && hours <= 24 && minutes >= 0 && minutes <= 60 && seconds >= 0 && seconds <= 60);
    }

//    Date timeDifference(const Date& otherDate) const {
//        int diffYears = otherDate.year - year;
//        int diffMonths = otherDate.month - month;
//        int diffDays = otherDate.day - day;
//        int diffHours = otherDate.hours - hours;
//        int diffMinutes = otherDate.minutes - minutes;
//        int diffSeconds = otherDate.seconds - seconds;
//
//        // Обробка випадку, коли різниця менша за 0
//        if (diffSeconds < 0) {
//            diffMinutes--;
//            diffSeconds += 60;
//        }
//        if (diffMinutes < 0) {
//            diffHours--;
//            diffMinutes += 60;
//        }
//        if (diffHours < 0) {
//            diffDays--;
//            diffHours += 24;
//        }
//        if (diffDays < 0) {
//            diffMonths--;
//            int lastMonthDays = daysInMonth[(month - 1 + 12) % 12];
//            diffDays += lastMonthDays;
//        }
//        if (diffMonths < 0) {
//            diffYears--;
//            diffMonths += 12;
//        }
//
//        // Створюємо та повертаємо новий об'єкт Date з різницею
//        Date difference(diffYears, diffMonths, diffDays, diffHours, diffMinutes, diffSeconds, "");
//        return difference;
//    }

    Date timeDifference(const Date& otherDate) const {
        int diffYears = year - otherDate.year;
        int diffMonths = month - otherDate.month;
        int diffDays = day - otherDate.day;
        int diffHours = hours - otherDate.hours;
        int diffMinutes = minutes - otherDate.minutes;
        int diffSeconds = seconds - otherDate.seconds;

        // Обробка випадку, коли різниця менша за 0
        while (diffSeconds < 0) {
            diffMinutes--;          // Зменшуємо хвилини на 1
            diffSeconds += 60;      // Додаємо 60 секунд, оскільки від'ємне значення
        }
        while (diffMinutes < 0) {
            diffHours--;            // Зменшуємо години на 1
            diffMinutes += 60;      // Додаємо 60 хвилин
        }
        while (diffHours < 0) {
            diffDays--;             // Зменшуємо дні на 1
            diffHours += 24;        // Додаємо 24 години
        }
        while (diffDays < 0) {
            diffMonths--;           // Зменшуємо місяці на 1
            int lastMonthDays = daysInMonth[(month - 2 + 12) % 12]; // Враховуємо попередній місяць
            diffDays += lastMonthDays; // Додаємо кількість днів у попередньому місяці
        }
        while (diffMonths < 0) {
            diffYears--;            // Зменшуємо роки на 1
            diffMonths += 12;       // Додаємо 12 місяців
        }

        // Створюємо та повертаємо новий об'єкт Date з різницею
        Date difference(diffYears, diffMonths, diffDays, diffHours, diffMinutes, diffSeconds, "");
        return difference;
    }




    void addTimeDifference(const Date& timeDiff) {
        year += timeDiff.year;
        month += timeDiff.month;
        day += timeDiff.day;
        hours += timeDiff.hours;
        minutes += timeDiff.minutes;
        seconds += timeDiff.seconds;

        // Обробка переповнень
        while(seconds >= 60) {
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
//                year++;
            }
        }
    }

    // Функція для віднімання різниці між моментами часу від поточного об'єкту Date
    void subtractTimeDifference(const Date& timeDiff) {
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




    int getDayOfWeek() const {
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12 * a - 2;
        int dayOfWeek = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
        return dayOfWeek;
    }

    int getWeekOfMonth() const {
        int dayOfWeek = getDayOfWeek();
        int weekNumber = (day + dayOfWeek - 1) / 7 + 1;
        return weekNumber;
    }

    int getWeekOfYear() const {
        int dayOfWeek = getDayOfWeek();
        int dayOfYear = 0;
        for (int i = 1; i < month; i++) {
            dayOfYear += daysInMonth[i - 1];
        }
        dayOfYear += day;

        int weekNumber = (dayOfYear + dayOfWeek - 1) / 7 + 1;
        return weekNumber;
    }

    void setYear(int y) {
        if (y < 1) {
        } else
            year = y;
    }

    void setMonth(int m) {
        if (m < 1 || m > 12) {
        } else
            month = m;
    }

    void setDay(int d) {
        if (d < 1 || d <= daysInMonth[month - 1]) {
        } else
            day = d;
    }

    void setHours(int h) {
        if (h <= 0 || h > 24) {
        } else
            hours = h;
    }

    void setMinutes(int min) {
        if (min <= 0 || min > 60) {
        } else
            minutes = min;
    }

    void setSeconds(int sec) {
        if (sec <= 0 || sec > 60) {
        } else
            seconds = sec;
    }

    int getYear() const { return year; }

    int getMonth() const { return month; }

    int getDay() const { return day; }

    int getHours() const { return hours; }

    int getMinutes() const { return minutes; }

    int getSeconds() const { return seconds; }

    string getDescription()const{return description;}



};





