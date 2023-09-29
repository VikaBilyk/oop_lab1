
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

        // Виводення поточної дати та іншої дати
        cout << "Current Date: ";
        cout << currentDate << endl;

        cout << "Another Date: ";
        cout << anotherDate << endl;

        // Обчислення різниці між датами
        //Виглядає як dateDifference = currentDate-anotherDate
        Date dateDifference = currentDate.timeDifference(anotherDate);
        cout<<'\n';


        // Додавання різниці до поточної дати
        //currentDate = currentDate + dateDifference;
        currentDate.addTimeDifference(dateDifference);
        cout << "After adding time difference to current Date: \n";
        cout << currentDate << endl;

        // Віднімання різниці від поточної дати
        // currentDate = currentDate - dateDifference
        currentDate.subtractTimeDifference(dateDifference);
        cout << "After subtracting time difference from Current Date: \n";
        cout << currentDate << endl;
        cout << "______________________________________\n";


        cout << "Sorting\n";
        vector<Date> dates;

        // Додавання об'єктів Date до вектора
        dates.push_back(Date(2023, 9, 28, 10, 30, 0));
        dates.push_back(Date(2020, 7, 27, 14, 0, 0));
        dates.push_back(Date(2013, 10, 29, 8, 45, 0));


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

    }