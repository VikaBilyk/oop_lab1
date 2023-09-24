//
// Created by Вікторія Білик on 21.09.2023.
//
#include <iostream>
#include "Date.h"

using namespace std;

int main()
{

    cout << "write date\n";
    int year,month,day;
    cin >> year >> month >> day;

         Day date (year,month,day);

    cout << date.is_date_correct();

    return 0;
}
