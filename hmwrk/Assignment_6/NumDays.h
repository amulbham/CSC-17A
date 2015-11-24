/* 
 * File:   NumDays.h
 * Author: Amul.bham
 *
 * Created on November 23, 2015, 9:22 PM
 */

#ifndef NUMDAYS_H
#define	NUMDAYS_H
#include <iostream>
#include <iomanip>
using namespace std;

class NumDays {
public:
    NumDays();
    Numdays(float hrs){hours = hrs;setDay(hours);}
    void setHrs(float h){hours = h;setDay(h);}
    float retHrs(){return hours;}
    float retDays(){return days;}
    float operator + (const NumDays &);
    float operator - (const NumDays &);
    void print(){
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<"Hours: "<<hours<<endl;
        cout<<"Days Worked: "<<days<<endl;
    
    }
    NumDays operator ++ ();
    NumDays operator -- ();
    
    NumDays(const NumDays& orig);
    virtual ~NumDays();
private:
    float hours, days;
    //Keep the set day private as we only set it if the hours have changed
    void setDay(float hrs){days = hrs/8.0;}
};

#endif	/* NUMDAYS_H */

