//
// Created by Вікторія Білик on 21.09.2023.
//
#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Event.h"


using namespace std;

int main()
{
int choice;
while(true){
    cout << "Choose the action: \n";
    cout << "Add the action : \n";
    cout << "Calculate the number of the week of the year: \n";
    cout << "Exit \n";
    cout << "Your choice: \n";
    cin >> choice;

    switch (choice) {
        case 1: {
            string desc;
            int year, month, day, hour, minute, second;

            cout << "Enter description of your event: \n";
            cin.ignore();
            getline(cin, desc);

            cout << "Enter year: \n";
            cin >> year;
            cout << "Enter month: \n";
            cin >> month;
            cout << "Enter day: \n";
            cin >> day;

            if(!Date::is_date_correct(year, month, day)){
                cout << "The date is incorrect! \n";
                break;
            }


        }
        
    }
}


    return 0;
}
