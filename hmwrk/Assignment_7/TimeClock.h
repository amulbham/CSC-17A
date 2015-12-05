/* 
 * File:   TimeClock.h
 * Author: Amul.bham
 *
 * Created on December 4, 2015, 9:30 PM
 */

#ifndef TIMECLOCK_H
#define	TIMECLOCK_H
#include <iostream>
#include "MilTime.h"
using namespace std;

class TimeClock : public MilTime {
public:
    TimeClock(): MilTime(){diff = 0;diffS = 0;}
    TimeClock(int start,int sec, int end,int sec2){
        //Determine the difference in the hours
        diff = start - end;
        //Determine the difference in the seconds
        diffS = sec - sec2;
        //Check to make sure the difference is positive
        if (diff < 0){diff *=-1;}
        if (diffS < 0){diffS *=-1;}
        milHours = diff;
        milSeconds = diffS;
        //Send the difference in seconds and hours to the convert to standard function
        convert(diff,diffS);
        
    }
    int giveDiff(){return diff;}
    int diffSec(){return diffS;}
    TimeClock(const TimeClock& orig);
    virtual ~TimeClock();
private:
    int diff,diffS;

};

#endif	/* TIMECLOCK_H */

