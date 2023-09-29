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
    Date();
    Date(int y, int m, int d, int h, int min, int sec, string des);

    bool isDateValid(int year, int month, int day);
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    bool isTimeValid() const;
    Date timeDifference(const Date& otherDate) const;
    void addTimeDifference(const Date& timeDiff);
    void subtractTimeDifference(const Date& timeDiff);
    int getDayOfWeek() const;
    int getWeekOfMonth() const;
    int getWeekOfYear() const;
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHours(int h);
    void setMinutes(int min);
    void setSeconds(int sec);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    string getDescription()const;
};
