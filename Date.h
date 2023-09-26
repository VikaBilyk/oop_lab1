//
// Created by Вікторія Білик on 24.09.2023.
//

#ifndef DATE_H
#define DATE_H

class Date{
public:

    int year, month, day, hour, minute, second;

Date(int y, int m, int d, int h, int min, int sec);
static bool is_date_correct(int year, int month, int day){
    //Базовий випадок
    if (year < 1 or month < 1 or month > 12 or day < 1) {
        return false;
    }
    static const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 and ((year % 400 == 0 and (year % 100 != 0 or year % 4 == 0))))
        return day <= 29;
    else
        return day <= days_in_month[month];
};

    bool is_date_correct();

    int getWeekNumber();
};


#endif //DATE_H
