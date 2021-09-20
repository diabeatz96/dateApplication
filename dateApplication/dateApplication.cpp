#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include"dayValue.h"

using namespace std;

int main()
{
    dayValue newDay;
    int day = 0, year = 0, month = 0;
    int choice = 0;
    ifstream inFile;
    ofstream outFile;

    inFile.open("dateInput.txt"); //Broken and trying to fix. Not too sure what issue is.
    if(inFile.fail())            //is it ok?
        { cout<<"Input file did not open please check it\n";
        return 1;
        }
    outFile.open("dateOutput.txt");
    if(outFile.fail())            //is it ok?
        { cout<<"output file did not open please check it\n";
        return 1;
        }
    
    
    cout << "Hi! This is Adam's day calculator program.\n";
    cout << "Would you like to input your own date into the console or read dates from a file? \nType 1 to input a date or 2 to access your files: ";
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            cout << "Welcome to the day calculator program, can you please input a date for us to store\n";
            cout << "Please input the month: ";
            cin >> month;
            cout << "Please input the day: ";
            cin >> day;
            cout << "Please input the year: ";
            cin >> year;
            newDay.setDate(year, month, day);
            newDay.print();
            outFile << "Your date: " << newDay.month << "/" << newDay.day << "/" << newDay.year << " is the weekday " << newDay.findWeekDay() << " and has a day value of " << newDay.findDayValue() << " (current day is inclusive) "; 
        }
        else if (choice == 2)
        {
            //newDay.setDate(year, month, day);
            if (inFile >> year >> month >> day)
            {
                newDay.setDate(year, month, day);
            } else
            {
                // print error message and exit}
                cout << "It's broken";
            }
            //do the loop while there are still numbers in the file
            while (inFile >> year >> month >> day)
            {
                outFile << "Your date: " << newDay.month << "/" << newDay.day << "/" << newDay.year << " is the weekday " << newDay.findWeekDay() << " and has a day value of " << newDay.findDayValue() << " (current day is inclusive) ";
                newDay.setDate(year, month, day);
            }
        }
    } while(choice < 1 || choice > 2);
    
    cout << "\n Thanks for using the day calculator application\n (Check your output file for write)";
    inFile.close();
    outFile.close();
    
    return 0;
}
