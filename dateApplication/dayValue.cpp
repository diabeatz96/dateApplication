#include "dayValue.h"
#include<iostream>
#include<string>
#include<fstream>



bool dayValue::isLeapYear(int year)
{
    if(year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    
    if(year % 100 == 0 && year % 400 == 0)
    {
        return true;
    }
    
    return false;
}

int dayValue::daysInMonth(int months)
{
    switch(months)
    {
        case 1:
            return 31;
        case 2:
            if(isLeapYear(year) == true)
            {
                return 29;
            }
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
         case 6:
             return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }

}

int dayValue::daysInYear()
{
    if (daysInMonth(month != 28))
    {
        return 365;
    }
    
    return 366;
}


int dayValue::findDayValue()
{
    int calculateLeapYears = (year - 1900) / 4;
    int calculateNormalYears = (year - 1900) - calculateLeapYears;
    int monthCalculate = 0;
    int dayCalculate = day;
    int yearSum = (calculateLeapYears * 366) + (calculateNormalYears * 365);
    for (int i = 1; i < month; i++)
    {
        monthCalculate += daysInMonth(i); 
    }
    int fullCalculation = (monthCalculate + yearSum + dayCalculate);

    if(isLeapYear(year) == true)
        return fullCalculation - 1;
    return fullCalculation;
}

std::string dayValue::findWeekDay() 
{
    int weekCalculation = findDayValue() % 7;

    switch(weekCalculation)
    {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wendsday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        
    default:
            return "Calculate is messed up";
    }
}

void dayValue::print()
{
    std::string weekDay = findWeekDay();
    std::cout << "Your date: " << month << "/" << day << "/" << year << " is the weekday " << findWeekDay() << " and has a day value of " << findDayValue() << " (current day is inclusive) "; 
}

/*void dayValue::printToFile()
{
    std::string weekDay = findWeekDay();
    std::cout << "Your date: " << month << "/" << day << "/" << year << " is the weekday " << findWeekDay() << " and has a day value of " << findDayValue() << " (current day is inclusive) "; 
}*/

dayValue::dayValue()
{
    day = 1;
    month = 1;
    year = 1900;
}

dayValue::dayValue(int days, int months, int years)
{
    day = days;
    month = months;
    year = years;
}
