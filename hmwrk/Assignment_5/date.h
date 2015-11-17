/* 
 * File:   date.cpp
 * Author: Amul Bham
 * Purpose: Class created for problem 1 of chapter 13
 * to store and output the date in different formats
 * 
 * Created on November 17, 2015, 1:13 PM
 */

#ifndef DATE_H
#define	DATE_H
#include <iostream>
using namespace std;

class date {
public:
    date(int d,int m,int y){
        day = d;
        month = m;
        year = y;
    }
    void dateShort();
    void dateLong();
    void dateAlt();
    virtual ~date();
private:
    int day, month, year;
    string mon;
    string getMonth(int);
};

#endif	/* DATE_H */

