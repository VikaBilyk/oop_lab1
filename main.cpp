//
// Created by Вікторія Білик on 21.09.2023.
#include "date.h"
#include "Sort.h"

void printDates(const std::vector<Date>& dates) {
    for (const Date& date : dates) {
        std::cout << date << std::endl;
    }
}


int main() {
    Date currentDate(2026, 9, 28, 15, 30, 45, "Current Date");
    Date anotherDate(2023, 8, 15, 10, 15, 30, "Another Date");

    // Виводимо поточну дату та іншу дату
    cout << "Current Date: ";
    cout<<currentDate << endl;

    cout << "Another Date: ";
    cout<<anotherDate<<endl;
    // Обчислюємо різницю між датами
    Date dateDifference = currentDate.timeDifference(anotherDate);
    cout << "Time Difference: " ;
    cout<<dateDifference<<endl;

    // Додаємо різницю до іншої дати
    currentDate.addTimeDifference(dateDifference);
    cout << "After adding time difference to current Date: \n" ;
    cout<<currentDate<<endl;

    // Віднімаємо різницю від поточної дати
    currentDate.subtractTimeDifference(dateDifference);
    cout << "After subtracting time difference from Current Date: \n" ;
    cout<<currentDate<<endl;
    cout << "______________________________________\n";

    //

    cout<<"Sorting\n";
    vector<Date> dates;

    // Додавання об'єктів Date до вектора
    dates.push_back(Date(2023, 9, 28, 10, 30, 0, "Event 1"));
    dates.push_back(Date(2020, 7, 27, 14, 0, 0, "Event 2"));
    dates.push_back(Date(2013, 10, 29, 8, 45, 0, "Event 3"));



    // Використовуйте різні компаратори та алгоритми сортування
    SortDate::insertionSort(dates, SortDate::compareByYear);  // Сортування за роком
    cout<<"______________________________________\n";
    cout<<"Sort by year - insertion sort\n";

    printDates(dates);



    SortDate::quickSort(dates, SortDate::compareByMonth);  // Сортування за місяцем
    cout<<"______________________________________\n";
    cout<<"Sort by month - quick sort\n";

    printDates(dates);


    SortDate::mergeSort(dates, SortDate::compareByDay);  // Сортування за днем
    cout<<"______________________________________\n";
    cout<<"Sort by day - merge sort\n";

    printDates(dates);


    SortDate::bubbleSort(dates, SortDate::compareByHours);  // Сортування за годиною
    cout<<"______________________________________\n";
    cout<<"Sort by hours - bubble sort\n";

    printDates(dates);


    cout<<"______________________________________\n";
    return 0;
}



//#include <iostream>
//#include <vector>
//#include "Date.h"
//#include "Sort.h"
//using namespace std;
//
//void printDates(const std::vector<Date>& dates) {
//    for (const Date& date : dates) {
//        std::cout << date << std::endl;
//    }
//}
//
//int main() {
//    Date currentDate(2026, 9, 28, 15, 30, 45, "Current Date");
//    Date anotherDate(2023, 8, 15, 10, 15, 30, "Another Date");
//
//    int choice;
//    do {
//        cout << "Menu:\n";
//        cout << "1. Display Current Date\n";
//        cout << "2. Display Another Date\n";
//        cout << "3. Calculate Time Difference\n";
//        cout << "4. Add Time Difference to Current Date\n";
//        cout << "5. Subtract Time Difference from Current Date\n";
//        cout << "6. Sorting\n";
//        cout << "7. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//            case 1:
//                cout << "Current Date: " << currentDate << endl;
//                break;
//            case 2:
//                cout << "Another Date: " << anotherDate << endl;
//                break;
//            case 3: {
//                Date dateDifference = currentDate.timeDifference(anotherDate);
//                cout << "Time Difference: " << dateDifference << endl;
//                break;
//            }
//            case 4:
//                currentDate.addTimeDifference(anotherDate.timeDifference(currentDate));
//                cout << "After adding time difference to Current Date:\n" << currentDate << endl;
//                break;
//            case 5:
//                currentDate.subtractTimeDifference(anotherDate.timeDifference(currentDate));
//                cout << "After subtracting time difference from Current Date:\n" << currentDate << endl;
//                break;
//            case 6: {
//                vector<Date> dates;
//
//                dates.push_back(Date(2023, 9, 28, 10, 30, 0, "Event 1"));
//                dates.push_back(Date(2020, 7, 27, 14, 0, 0, "Event 2"));
//                dates.push_back(Date(2013, 10, 29, 8, 45, 0, "Event 3"));
//
//                SortDate::insertionSort(dates, SortDate::compareByYear);
//                cout << "Sort by year - insertion sort\n";
//                printDates(dates);
//
//                SortDate::quickSort(dates, SortDate::compareByMonth);
//                cout << "Sort by month - quick sort\n";
//                printDates(dates);
//
//                SortDate::mergeSort(dates, SortDate::compareByDay);
//                cout << "Sort by day - merge sort\n";
//                printDates(dates);
//
//                SortDate::bubbleSort(dates, SortDate::compareByHours);
//                cout << "Sort by hours - bubble sort\n";
//                printDates(dates);
//                break;
//            }
//            case 7:
//                cout << "Exiting program\n";
//                break;
//            default:
//                cout << "Invalid choice. Please enter a valid option.\n";
//        }
//    } while (choice != 7);
//
//    return 0;
//}
