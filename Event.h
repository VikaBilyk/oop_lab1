//
// Created by Вікторія Білик on 25.09.2023.
//

#ifndef EVENT_H
#define EVENT_H
#include <string>
#include "Date.h"
using namespace std;

class Event{
public:
    string description;
    Date date;
    Event(string& desc, Date& dt);
};

#endif //EVENT_H
