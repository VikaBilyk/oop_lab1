//
// Created by Вікторія Білик on 21.09.2023.
//

#include <iostream>


using namespace std;


bool is_data_correct(int year, int month, int day){

    if(year < 1 or month < 1 or month > 12 or day < 1)
        return false;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(year % 400 == 0 and (year % 100 != 0 or year % 4 == 0))
        days_in_month[1] = 29; // типу високосний
        return day <= days_in_month[month];

}
int main()
{

cout << is_data_correct(2020, 4, 6);
    return 0;
}
