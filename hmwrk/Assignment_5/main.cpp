/*Name: Amul Bham
 11/17/2015
 Purpose: Menu for Assignment 5 - Classes and Objects*/


//Library includes Here!!!
#include <iostream>
#include <cstring>
#include "date.h"
#include "personal.h"

using namespace std;

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
    cout<<"Menu for Assignment 5"<<endl;
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
        int x,y,z; //Variable to hold the user inputted values
        char again;//Used to determine if the user would like to re run
        //Get the day, month, and year from the user, Validate user input
        _day:
        cout<<"What is the day?: "; cin>>x;
        if (x>31 || x<1){cout<<endl<<"Day must be between 1-31!"<<endl;
        goto _day;}
        
        _month:
        cout<<"What is the month?: "; cin>>y;
        if (y>12 || y<1){cout<<endl<<"Month must be between 1-12!"<<endl;
        goto _month;}
        
        _year:
            cout<<"What is the year?: "; cin>>z;
            cout<<endl;
            
         //Create a new object for the date, fill the constructor with
            //The required information date, year, month
            date current(x,y,z);
            
        //Determine how the user would like the date to be outputted
            do{ 
            cout<<"How would you like the date formatted?"<<endl;
            cout<<"Standard(1) - Long(2) - Alternative (3)"<<endl;
            cin>>x;
        //Output the formatted date 
            switch(x){
                case 1: current.dateShort();break;
                case 2: current.dateLong(); break;
                case 3: current.dateAlt(); break;
                default: current.dateShort();break;
            }
            cout<<"Would you like the date in a different format? y/n"<<endl;
            cin.ignore(); cin.get(again);
            //Loop incase user picked wrong date format
          }while(tolower(again) == 'y');  
           
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        //Declare variable to temp store the information
        string x;
        int y;
        personal me;
        //Get personal information from the user
        cout<<"Please enter your name: ";cin>>x;
        me.setName(x);
        
        
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
}


void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}