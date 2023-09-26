//
// Created by Вікторія Білик on 26.09.2023.
//

#ifndef SORTINGSTRATEGY_H
#define SORTINGSTRATEGY_H

#include <vector>
#include "Event.h"
class SortingStrategy {
public:
    virtual void sort(std::vector<Event>& events) = 0;
};

#endif //SORTINGSTRATEGY_H
