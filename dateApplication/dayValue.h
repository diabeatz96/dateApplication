#pragma once
#include <string>

struct dayValue
{

    void setDate(int years, int months, int days)
    {
        
        year = years;
        month = months;
        day = days;
        
    }

    void print();
    int findDayValue();
    std::string findWeekDay();
    bool isLeapYear(int year);
    int daysInMonth(int month);
    int daysInYear();
    
    
    dayValue();
    dayValue(int, int, int);
    
    
    bool leapYear;
    int year;
    int day;
    int month;
    int daysCounter;
};
