//
// Created by Вікторія Білик on 25.09.2023.
//

#include "Time.h"
Time::Time(int h, int m, int s)
: hour(h), minute(m), second(s){}

bool Time::is_correct(){
    return (hour>= 0 and hour < 24 and minute >= 0 and minute < 60 and second >= 0 and second < 60);
}