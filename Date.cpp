//
// Created by Вікторія Білик on 24.09.2023.
//

#include "Date.h"
bool Day::is_date_correct() {
        //Базовий випадок
        if (year < 1 or month < 1 or month > 12 or day < 1) {
            return false;
        }
        int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 400 == 0 and (year % 100 != 0 or year % 4 == 0)) {
            days_in_month[2] = 29; //  високосний
        }
        return day <= days_in_month[month];
}