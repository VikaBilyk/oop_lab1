
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

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static vector<string> daysOfWeek;

public:
    // Конструктор за замовчуванням без параметрів.
    Date();

    // Конструктор, який приймає рік, місяць, день, години, хвилини, секунди та опис дати.
    Date(int y, int m, int d, int h, int min, int sec);


    // Перевірка, чи є задана дата коректною.
    bool isDateValid(int year, int month, int day);
    bool isDateValid();



    // Перевірка, чи є час об'єкта Date коректним (години, хвилини та секунди).
    bool isTimeValid() const;
    bool isTimeValid(int hours, int minutes, int seconds) const;

    // Обчислення різниці між двома об'єктами Date і повернення результату.
    void timeDifferencePrint()const;
    Date timeDifference(const Date& otherDate) const;


    // Додавання часової різниці до поточного об'єкта Date.
    void addTimeDifference(const Date& timeDiff);

    // Віднімання часової різниці від поточного об'єкта Date.
    void subtractTimeDifference(const Date& timeDiff);

    // Отримання дня тижня для поточної дати.
    int getDayOfWeek() const;

    // Отримання номера тижня в місяці для поточної дати.
    int getWeekOfMonth() const;

    // Отримання номера тижня в році для поточної дати.
    int getWeekOfYear() const;

    // Встановлення року для поточного об'єкта Date.
    void setYear(int y);

    // Встановлення місяця для поточного об'єкта Date.
    void setMonth(int m);

    // Встановлення дня для поточного об'єкта Date.
    void setDay(int d);

    // Встановлення годин для поточного об'єкта Date.
    void setHours(int h);

    // Встановлення хвилин для поточного об'єкта Date.
    void setMinutes(int min);

    // Встановлення секунд для поточного об'єкта Date.
    void setSeconds(int sec);

    // Отримання значення року для поточного об'єкта Date.
    int getYear() const;

    // Отримання значення місяця для поточного об'єкта Date.
    int getMonth() const;

    // Отримання значення дня для поточного об'єкта Date.
    int getDay() const;

    // Отримання значення годин для поточного об'єкта Date.
    int getHours() const;

    // Отримання значення хвилин для поточного об'єкта Date.
    int getMinutes() const;

    // Отримання значення секунд для поточного об'єкта Date.
    int getSeconds() const;

    // Перевантажений оператор виводу, щоб можна було виводити об'єкти Date у потік.
    friend ostream& operator << (ostream& os, const Date& date);

    friend istream& operator>>(istream& in, Date& date);
};
