/* 
 * File:   main.cpp
 * Author: Amul.bham
 *Purpose: Assignment 6 - Chapter 14 Homework
 * Created on November 23, 2015, 6:43 PM
 */

//Library includes Here!!!
#include <iostream>

using namespace std;
//Classes created for each problem 
#include "Numbers.h"
#include "DayOfYear.h"
#include "DayOfYear2.h"

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for Assignment 6"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
        
        //Declare Variables
        int num; //Value to be converted
        
        //Initialize the number for conversion
        start:
        cout<<"Please enter a dollar amount between 0 and 9999"<<endl;
        cout<<"$ "; cin>>num;
        
        //Ensure the number falls within the proper range
        if (num>9999 || num<0){cout<<"Error!"<<endl; goto start;}
        
        //Create a new instance of numbers class - outputs the conversion
        Numbers conv(num);
        
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        //Declare variables
        int day;
        
        redo:
        //Initialize the day the user would like to see
        cout<<"Enter the day of the year you would like to see"<<endl;
        cin>>day;
        
        //Validate the user input to make sure it is valid day
        if (day<0 || day>365){cout<<"Error! Day must be between 1-365"<<endl;goto redo;}
        
        //Create a new dayofyear object and output the conversion
        DayOfYear date(day);
        
        
            
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
        //Declare variables
        int day;
        
        redo:
        //Initialize the day the user would like to see
        cout<<"Enter the day of the year you would like to see"<<endl;
        cin>>day;
        
        //Validate the user input to make sure it is valid day
        if (day<0 || day>365){cout<<"Error! Day must be between 1-365"<<endl;goto redo;}
        
        //Create three instances of the dayofyear class, once to represent
        //the current day, the previous day, and the upcoming day. 
        cout<<"Current Day"<<endl;
        DayOfYear2 date(day);
        cout<<"Previous Day"<<endl;
        DayOfYear2 date3 = --date;
        cout<<"Next Day"<<endl;
        DayOfYear2 date2 = ++date;
        
       
        
        
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
}



void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}