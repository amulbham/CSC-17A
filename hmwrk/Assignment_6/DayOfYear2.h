/* 
 * File:   DayOfYear2.h
 * Author: Amul.bham
 *
 * Created on November 23, 2015, 8:32 PM
 */

#ifndef DAYOFYEAR2_H
#define	DAYOFYEAR2_H
#include <iostream>
using namespace std;
class DayOfYear2 {
public:
    //Constructor sets the day -> then determines the string month and day, then prints the day and month
    DayOfYear2(int d){day = d;month();print();}
    DayOfYear2(const DayOfYear2& orig);
    //Determines the month of the given integer
    void month();
    
    DayOfYear2 operator ++(){
        day +=2;
        if (day>365){day = 1;}
        month();
        print();
        return *this;
    }
    DayOfYear2 operator --(){
        --day;
        if (day<1){day = 365;}
        month();
        print();
        return *this;
    }
    //Prints out the month string and day next to each other for the user
    void print(){cout<<mon<<" "<<dmon<<endl;}
    virtual ~DayOfYear2();
private:
    int day; //Original day #
    int dmon; //day that corresponds to the day of the month
    string mon;//String to hold the string of the month name
};


#endif	/* DAYOFYEAR2_H */

