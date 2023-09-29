
#include "Date.h"
#include "Sort.h"


static void printDates(vector<Date>& dates) {
    for (const Date& date : dates) {
        std::cout << date << std::endl;
    }
}

int main() {
        Date check;
        cout << "Print the date you want to check: ";
        cin >> check;
        if(check.isDateValid() and check.isTimeValid()){
            cout << "Date is valid!\n";
            cout<<check<<endl;
        }
        else{
            cout << "Date is invalid!\n";

        }

        Date currentDate(2023, 9, 29, 15, 30, 45);
        Date anotherDate(2023, 8, 15, 10, 15, 30);

        // Виводимо поточну дату та іншу дату
        cout << "Current Date: ";
        cout << currentDate << endl;

        cout << "Another Date: ";
        cout << anotherDate << endl;
        // Обчислюємо різницю між датами
        Date dateDifference = currentDate.timeDifference(anotherDate);
        cout<<'\n';


        // Додаємо різницю до іншої дати
        currentDate.addTimeDifference(dateDifference);
        cout << "After adding time difference to current Date: \n";
        cout << currentDate << endl;

        // Віднімаємо різницю від поточної дати
        currentDate.subtractTimeDifference(dateDifference);
        cout << "After subtracting time difference from Current Date: \n";
        cout << currentDate << endl;
        cout << "______________________________________\n";

        //

        cout << "Sorting\n";
        vector<Date> dates;

        // Додавання об'єктів Date до вектора
        dates.push_back(Date(2023, 9, 28, 10, 30, 0));
        dates.push_back(Date(2020, 7, 27, 14, 0, 0));
        dates.push_back(Date(2013, 10, 29, 8, 45, 0));



        // Використовуйте різні компаратори та алгоритми сортування
        SortDate::insertionSort(dates, SortDate::compareByYear);  // Сортування за роком
        cout << "______________________________________\n";
        cout << "Sort by year - insertion sort\n";

        printDates(dates);


        SortDate::quickSort(dates, SortDate::compareByMonth);  // Сортування за місяцем
        cout << "______________________________________\n";
        cout << "Sort by month - quick sort\n";

        printDates(dates);


        SortDate::mergeSort(dates, SortDate::compareByDay);  // Сортування за днем
        cout << "______________________________________\n";
        cout << "Sort by day - merge sort\n";

        printDates(dates);


        SortDate::bubbleSort(dates, SortDate::compareByHours);  // Сортування за годиною
        cout << "______________________________________\n";
        cout << "Sort by hours - bubble sort\n";

        printDates(dates);


        cout << "______________________________________\n";
        return 0;


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

//
//    return 0;
    }