//
// Created by Вікторія Білик on 24.09.2023.
//

#include "Date.h"
Date::Date(int y, int m, int d, int h, int min, int sec)
:year(y), month(m), day(d), hour(h), minute(min), second(sec) {}

bool Date::is_date_correct() {
        //Базовий випадок
        if (year < 1 or month < 1 or month > 12 or day < 1) {
            return false;
        }
        static const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2 and ((year % 400 == 0 and (year % 100 != 0 or year % 4 == 0))))
            return day <= 29;
        else
            return day <= days_in_month[month];
}

int Date::getWeekNumber(){

    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + y/4 - y/100 + y/400 + (31 * m) / 12) % 7;
}


