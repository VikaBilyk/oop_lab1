//
// Created by Вікторія Білик on 29.09.2023.
//

#ifndef OOP_LAB1_SORT_H
#define OOP_LAB1_SORT_H

#include "date.h"
class SortDate {
public:

    // Компаратори для порівняння об'єктів Date
    static bool compareByYear(const Date& date1, const Date& date2) {
        return date1.getYear() < date2.getYear();
    }

    static bool compareByMonth(const Date& date1, const Date& date2) {
        return date1.getMonth() < date2.getMonth();
    }

    static bool compareByDay(const Date& date1, const Date& date2) {
        return date1.getDay() < date2.getDay();
    }

    static bool compareByHours(const Date& date1, const Date& date2) {
        return date1.getHours() < date2.getHours();
    }

    static bool compareByMinutes(const Date& date1, const Date& date2) {
        return date1.getMinutes() < date2.getMinutes();
    }

    static bool compareBySeconds(const Date& date1, const Date& date2) {
        return date1.getSeconds() < date2.getSeconds();
    }

    // Алгоритм сортування вставками (insertion sort)
    static void insertionSort(vector<Date>& dates, bool (*compareFunc)(const Date&, const Date&)) {
        int n = dates.size();
        for (int i = 1; i < n; i++) {
            Date key = dates[i];
            int j = i - 1;
            while (j >= 0 && compareFunc(dates[j], key)) {
                dates[j + 1] = dates[j];
                j--;
            }
            dates[j + 1] = key;
        }
    }

    // Алгоритм сортування quicksort
    static void quickSort(vector<Date>& dates, bool (*compareFunc)(const Date&, const Date&)) {
        quickSortRecursive(dates, 0, dates.size() - 1, compareFunc);
    }

    static void quickSortRecursive(vector<Date>& dates, int low, int high, bool (*compareFunc)(const Date&, const Date&)) {
        if (low < high) {
            int pivotIndex = partition(dates, low, high, compareFunc);
            quickSortRecursive(dates, low, pivotIndex - 1, compareFunc);
            quickSortRecursive(dates, pivotIndex + 1, high, compareFunc);
        }
    }

    static int partition(vector<Date>& dates, int low, int high, bool (*compareFunc)(const Date&, const Date&)) {
        Date pivot = dates[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (compareFunc(dates[j], pivot)) {
                i++;
                swap(dates[i], dates[j]);
            }
        }
        swap(dates[i + 1], dates[high]);
        return i + 1;
    }

    // Алгоритм сортування merge sort
    static void mergeSort(vector<Date>& dates, bool (*compareFunc)(const Date&, const Date&)) {
        mergeSortRecursive(dates, 0, dates.size() - 1, compareFunc);
    }

    static void mergeSortRecursive(vector<Date>& dates, int low, int high, bool (*compareFunc)(const Date&, const Date&)) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSortRecursive(dates, low, mid, compareFunc);
            mergeSortRecursive(dates, mid + 1, high, compareFunc);
            merge(dates, low, mid, high, compareFunc);
        }
    }

    static void merge(vector<Date>& dates, int low, int mid, int high, bool (*compareFunc)(const Date&, const Date&)) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<Date> left(n1);
        vector<Date> right(n2);

        for (int i = 0; i < n1; i++) {
            left[i] = dates[low + i];
        }
        for (int j = 0; j < n2; j++) {
            right[j] = dates[mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = low;

        while (i < n1 && j < n2) {
            if (compareFunc(left[i], right[j])) {
                dates[k] = left[i];
                i++;
            } else {
                dates[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            dates[k] = left[i];
            i++;
            k++;
        }

        while (j < n2) {
            dates[k] = right[j];
            j++;
            k++;
        }
    }

    // Алгоритм сортування bubble sort
    static void bubbleSort(vector<Date>& dates, bool (*compareFunc)(const Date&, const Date&)) {
        int n = dates.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (compareFunc(dates[j], dates[j + 1])) {
                    swap(dates[j], dates[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
};

#endif //OOP_LAB1_SORT_H
