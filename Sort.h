#ifndef OOP_LAB1_SORT_H
#define OOP_LAB1_SORT_H

#include "Date.h"

class SortDate {
public:
    // Компаратори для порівняння об'єктів Date

    // Порівняння за роком.
    static bool compareByYear(const Date& date1, const Date& date2);

    // Порівняння за місяцем.
    static bool compareByMonth(const Date& date1, const Date& date2);

    // Порівняння за днем.
    static bool compareByDay(const Date& date1, const Date& date2);

    // Порівняння за годинами.
    static bool compareByHours(const Date& date1, const Date& date2);


    /*------ Алгоритм сортування вставками (insertion sort) -------*/

    // Сортування вектора дат за допомогою алгоритму сортування вставками.
    // Параметр compareFunc - функція-компаратор, яка визначає, за яким критерієм порівнювати дати.
    static void insertionSort(std::vector<Date>& dates, bool (*compareFunc)(const Date&, const Date&));


    /*------- Алгоритм сортування quicksort ---------*/

    // Головна функція для сортування вектора дат за допомогою алгоритму quicksort.
    static void quickSort(std::vector<Date>& dates, bool (*compareFunc)(const Date&, const Date&));

    // Рекурсивна функція для сортування підмасиву методом quicksort.
    static void quickSortRecursive(std::vector<Date>& dates, int low, int high, bool (*compareFunc)
    (const Date&, const Date&));

    // Внутрішня функція для розділення масиву під частини для алгоритму quicksort.
    static int partition(std::vector<Date>& dates, int low, int high, bool (*compareFunc)
    (const Date&, const Date&));


    /*------- Алгоритм сортування merge sort -----------*/

    // Головна функція для сортування вектора дат за допомогою алгоритму merge sort.
    static void mergeSort(std::vector<Date>& dates, bool (*compareFunc)(const Date&, const Date&));

    // Рекурсивна функція для сортування підмасиву методом merge sort.
    static void mergeSortRecursive(std::vector<Date>& dates, int low, int high, bool (*compareFunc)
    (const Date&, const Date&));

    // Внутрішня функція для об'єднання двох підмасивів у відсортований масив.
    static void merge(std::vector<Date>& dates, int low, int mid, int high, bool (*compareFunc)
    (const Date&, const Date&));

    /*---------- Алгоритм сортування bubble sort ----------*/

    // Сортування вектора дат за допомогою алгоритму сортування методом "бульбашки".
    static void bubbleSort(std::vector<Date>& dates, bool (*compareFunc)(const Date&, const Date&));
};


#endif //OOP_LAB1_SORT_H
