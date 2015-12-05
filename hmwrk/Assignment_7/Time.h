/* 
 * File:   Time.h
 * Author: Amul.bham
 *
 * Created on December 4, 2015, 7:51 PM
 */

#ifndef TIME_H
#define	TIME_H
using namespace std;
#include <iostream>

class Time
 {
 protected:
 int hour;
 int min;
 int sec;
 public:
 // Default constructor
 Time()
 { hour = 0; min = 0; sec = 0; }

 // Constructor
 Time(int h, int m, int s)
 { hour = h; min = m; sec = s; }

 // Accessor functions
 int getHour() const
 { return hour; }

 int getMin() const
 { return min; }

 int getSec() const
 { return sec; }
 };

#endif


