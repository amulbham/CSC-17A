/* 
 * File:   date.cpp
 * Author: Amul Bham
 * Purpose: Class created for problem 1 of chapter 13
 * to store and output the date in different formats
 * 
 * Created on November 17, 2015, 1:13 PM
 */

#include "date.h"
#include <iostream>
using namespace std;

void date::dateShort(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
string date:: getMonth(int m){
    switch(m){
        case 1: return "January"; break;
        case 2: return "February";break;
        case 3: return "March"; break;
        case 4: return "April"; break;
        case 5: return "May"; break;
        case 6: return "June"; break;
        case 7: return "July"; break;
        case 8: return "August"; break;
        case 9: return "September"; break;
        case 10: return "October"; break;
        case 11: return "November";break;
        case 12: return "December";break;
    }

}
void date::dateLong(){
    mon = getMonth(month);
    cout<<mon<<" "<<day<<","<<year<<endl;
}

void date::dateAlt(){
    mon = getMonth(month);
    cout<<day<<" "<<mon<<" "<<year<<endl;
}


date::~date() {
}

