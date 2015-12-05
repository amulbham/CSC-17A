/* 
 * File:   main.cpp
 * Author: Amul Bham
 * Purpose: Menu for Chapter 15 Assignment
 *
 * Created on December 2, 2015, 11:51 AM
 */


//Libraries
#include <iostream>
#include <string>
#include <cstring>

#include "ProductionWorker.h"
#include "Employee.h"
#include "Time.h"
#include "ProductionWorker.h"
#include "MilTime.h"
#include "TimeClock.h"
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
    cout<<"Menu for the Assignment_7"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 4 for problem 2"<<endl;
    cout<<"Type 5 for problem 3"<<endl;
    cout<<"Type 6 for problem 4"<<endl;
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
        int s,nm; //Int to hold emp number and shift
        float p;  //rate of pay
        string hire; //hire date
        string n;   //name of the employee
        
        //Initialize the variables from the user
        cout<<"Please enter the employee name: "; getline(cin,n);
        error:
        cout<<"Please enter the hire date: "; getline(cin,hire);
        if (sizeof(hire)>9){cout<<"Please enter as xx/xx/xxxx format"<<endl;goto error;}
        cout<<"Please enter employee number: "; cin>>nm;
        cout<<"Please enter the rate of pay: $"; cin>>p;
        shift:
        cout<<"Please enter the shift (1 or 2) :"; cin>>s;
        if (s != 1 && s != 2){cout<<"Enter a valid shift"<<endl;goto shift;}
        
        //Create object for the employee with the required parameters
        ProductionWorker x(n,nm,hire,s,p);
        
        //Output the record of the employee
        x.giveName();
        x.giveDate();
        x.giveNum();
        x.givePay();
        x.giveShift();
        
        
}

void problem2(){
        cout<<"In problem # 4"<<endl<<endl;
        
        //Declare Variables
        int milHours;//24 hour format for hours
        int milSec; //24 hour format for seconds 
        int hour; //to store the standard hours
        int min;
        int sec; //to store the standard seconds
        
        //Get the military hours for conversion from the user
        _hours:
        cout<<"Please Enter the time in Military Format: "; cin>>milHours;
        if (milHours>2359 || milHours<0 || milHours %100>59 || milHours %100<0){cout<<"Invalid Hour!"<<endl;
        goto _hours;}
        _sec:
        cout<<"Please enter the seconds: "; cin>>milSec;
        if (milSec>59 || milSec<0){cout<<"Invalid seconds!"<<endl; 
        goto _sec;}
        
        //Create a new object for the military time class
        MilTime x(milHours,milSec);
        
        //Output the hours in standard time format for the user
        hour = x.getHour();
        if (hour == 0){hour = 12;}
        sec = x.getSec();
        min = x.getMin();
        
        cout<<"Military Time - "<<milHours<<" hours "<<milSec<<" seconds"<<endl;
        if (milHours>=1200){
        cout<<"Standard Time - "; x.check(hour); cout<<hour; cout<<":"; x.check(min); cout<<min; cout<<":"; x.check(sec); cout<<sec<<" PM"<<endl<<endl;
        }else if (milHours<1200){
        cout<<"Standard Time - "; x.check(hour); cout<<hour; cout<<":"; x.check(min); cout<<min; cout<<":"; x.check(sec); cout<<sec<<" AM"<<endl<<endl;
        }
        
}

void problem3(){
        cout<<"In problem # 5"<<endl<<endl;
        
        //Declare Variables
        int hours[2]; //Starting time and ending time
        int sec[2];
        int diff,diffS; //To hold the difference in hours and seconds
        
        cout<<"This program determines the time elapsed between two two times"<<endl;
        cout<<endl;
        
        //Initilize the the starting and ending time
        
        //Use a for loop to get two inputs for times, verify the inputs
        for(int i = 0; i<2; i++){
        cout<<"Time "<<i+1<<": "<<endl;    
        _hours:
            if (i == 0){cout<<"Please enter the starting time : ";}
            else{cout<<"Please enter the ending time: ";}
            cin>>hours[i];
        if (hours[i]>2359 || hours[i]<0 || hours[i] %100>59 || hours[i] %100<0){cout<<"Invalid Hour!"<<endl;
        goto _hours;}
        _sec:
        cout<<"Please enter the seconds: "; cin>>sec[i];
        if (sec[i]>59 || sec[i]<0){cout<<"Invalid seconds!"<<endl; 
        goto _sec;}
        cout<<endl;
        }
        
        //Create a new TimeClock object
        TimeClock x(hours[0],sec[0],hours[1],sec[1]);
        
        //Output the difference between the two times
        cout<<"Time Elapsed: "; x.check(x.getHour()); cout<<x.getHour()
        <<":"; x.check(x.getMin()); cout<<x.getMin()<<":";
        x.check(x.getSec()); cout<<x.getSec()
                <<" (hrs:mins:secs)"<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}