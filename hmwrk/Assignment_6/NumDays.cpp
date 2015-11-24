/* 
 * File:   NumDays.cpp
 * Author: Amul.bham
 * 
 * Created on November 23, 2015, 9:22 PM
 */

#include "NumDays.h"
#include <iomanip>
#include <iostream>
using namespace std;

NumDays::NumDays() {
    hours = 0;
    days = 0;
}
float NumDays::operator +(const NumDays &right){
    float sum;
    sum = hours + right.hours;
    return sum;
}

float NumDays::operator - (const NumDays &right){
    float diff;
    diff = hours - right.hours;
    //Check if the value is negative, if so make positive
    if (diff < 0){diff *=-1;}
    return diff;

}

NumDays NumDays::operator ++(){
    hours ++;
    setHrs(hours);
    //Call the set hours function which resets the hours as well as recalculating the new day
    
    return *this;
}

NumDays NumDays::operator --(){
    hours--;
    setHrs(hours);
    return *this;

}
NumDays::NumDays(const NumDays& orig) {
}

NumDays::~NumDays() {
}

