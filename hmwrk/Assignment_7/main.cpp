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
        cout<<"In problem # 2"<<endl<<endl;
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