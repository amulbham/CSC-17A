/* 
 * File:   DayOfYear.h
 * Author: Amul.bham
 *
 * Created on November 23, 2015, 7:59 PM
 */

#include <iostream>

using namespace std;
#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H

class DayOfYear {
public:
    //Constructor sets the day -> then determines the string month and day, then prints the day and month
    DayOfYear(int d){day = d;month();print();}
    DayOfYear(const DayOfYear& orig);
    //Determines the month of the given integer
    void month();
    //Prints out the month string and day next to each other for the user
    void print(){cout<<mon<<" "<<dmon<<endl;}
    virtual ~DayOfYear();
private:
    int day; //Original day #
    int dmon; //day that corresponds to the day of the month
    string mon;//String to hold the string of the month name
};

#endif	/* DAYOFYEAR_H */

