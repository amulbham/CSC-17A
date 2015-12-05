/* 
 * File:   MilTime.h
 * Author: Amul.bham
 *
 * Created on December 4, 2015, 7:57 PM
 */

#ifndef MILTIME_H
#define	MILTIME_H
#include "Time.h"
#include <iostream>
using namespace std;

class MilTime: public Time {
public:
    MilTime():Time(){
        milHours = 0;
        milSeconds = 0;
    }
    MilTime(int mH,int mS){
        milHours = mH;
        milSeconds = mS;
        convert(mH,mS);
    };
    void convert (int mH, int mS){
        if (mH<1200){hour = mH / 100;min = mH % 100;sec = mS;}
        else if (mH>=1200){hour = (mH - 1200) /100;min = (mH - 1200)%100;sec = mS;}
        if (min>60){min -=40;}
    }
    void setTime(int h, int s){
        milHours = h;
        milSeconds = s;
        convert(h,s);
    }
    //Checks if the digit is 0, if so, add another 0 to fit 00:00:00 format
    void check(int x){
        if (x<10){cout<<"0";}
    }
    int getMhours(){return milHours;}
    int getMsec(){return milSeconds;}
    MilTime(const MilTime& orig);
    virtual ~MilTime();
protected:
    int milHours;
    int milSeconds;
    

};

#endif	/* MILTIME_H */

