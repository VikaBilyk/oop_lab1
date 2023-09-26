//
// Created by Вікторія Білик on 25.09.2023.
//

#ifndef TIME_H
#define TIME_H
class Time{
public:
    int hour, minute, second;
    Time(int h, int m, int s);
    bool is_correct();
};

#endif //OOP_LAB1_TIME_H
