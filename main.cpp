//
// Created by Вікторія Білик on 21.09.2023.
//
#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Event.h"


using namespace std;

int main(){

    int choice;

    while(true){
        cout << "Choose the action: \n";
        cout << "1. Add the action : \n";
        cout << "2. Calculate the number of the week of the year: \n";
        cout << "3. Exit \n";
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

                cout << "Enter hours: \n";
                cin >> hour;
                cout << "Enter minutes: \n";
                cin >> minute;
                cout << "Enter seconds: \n";
                cin >> second;

            Time time(hour, minute, second);
            if(!time.is_correct()) {
                cout << "Incorrect time format!" << endl;
                break;
            }



        }
        
    }
}


    return 0;
}
