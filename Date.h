//
// Created by Вікторія Білик on 24.09.2023.
//

#ifndef DATE_H
#define DATE_H

class Date{
public:
    int year, month, day, hour, minute, second;
Date(int y, int m, int d, int h, int min, int sec);
static bool is_date_correct(int year, int month, int day);

    bool is_date_correct();
};

#endif //DATE_H
