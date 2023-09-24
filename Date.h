//
// Created by Вікторія Білик on 24.09.2023.
//

#ifndef DATE_H
#define DATE_H


class Year{
protected:
    int year;
public:
    Year(int year):year(year){}
};
class Month: public Year
{
protected:
    int month;
public:
    Month(int year,int month):Year(year),month(month){}
};
class Day: public Month
{
protected:
    int day;
public:
    Day(int year,int month,int day):Month(year,month),day(day){}
    bool is_date_correct();
};
class Time: public Day
{
protected:
    int hours,minute,second;
public:
    Time(int year,int month,int day,int hours,int minute,int second)
    :Day(year,month,day),hours(hours),minute(minute),second(second){}
};
#endif //DATE_H
