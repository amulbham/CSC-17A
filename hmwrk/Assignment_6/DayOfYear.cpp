/* 
 * File:   DayOfYear.cpp
 * Author: Amul.bham
 * 
 * Created on November 23, 2015, 7:59 PM
 */

#include "DayOfYear.h"
#include <iostream>

using namespace std;

DayOfYear::DayOfYear(const DayOfYear& orig) {
}


//Determines the month and the day of the month that the given integer corresponds too
void DayOfYear::month(){
    if (day<=31){mon = "January"; dmon = day;}
    else if (day>31 && day<=59){mon = "February"; dmon = day - 31;}
    else if (day>59 && day <= 90){mon = "March"; dmon = day - 59;}
    else if (day>90 && day <= 120){mon = "April"; dmon = day - 90;}
    else if (day>120 && day <=151){mon = "May"; dmon = day - 120;}
    else if (day>151 && day <= 181){mon = "June"; dmon = day - 151;}
     else if (day>181 && day <= 212){mon = "July"; dmon = day - 181;}
     else if (day>212 && day <= 243){mon = "August"; dmon = day - 212;}
     else if (day>243 && day <= 273){mon = "September"; dmon = day - 243;}
     else if (day>273 && day <= 304){mon = "October"; dmon = day - 273;}
     else if (day>304 && day <= 334){mon = "November"; dmon = day - 304;}
     else if (day>334){mon = "December"; dmon = day - 334;}
}

DayOfYear::~DayOfYear() {
}

