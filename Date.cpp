//
// Created by Вікторія Білик on 24.09.2023.
//

#include "Date.h"

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

bool Date::is_data_correct(int year, int month, int day){

    if(year < 1 or month < 1 or month > 12 or day < 1)
        return false;

    else {
        int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 400 == 0 and (year % 100 != 0 or year % 4 == 0))
            days_in_month[2] = 29; // типу високосний
        return day <= days_in_month[month];
    }

}