/* 
 * File:   main.cpp
 * Author: Amul.bham
 *
 * Created on October 27, 2015, 5:09 PM
 */

//Library includes Here!!!
#include <iostream>     
#include <algorithm>    
#include <ctime>        
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;
 
//Structures
//Problem #2
struct Employee {
            string name;
            float hrs;
            float rtepy;
            float total;
        };

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

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
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
      cout<<"In problem # 1"<<endl<<endl;
      //Declare Structures
      struct Userinfo {
          int aNum; //account number
          float bal;//user balance
          float checks;//sum of checks written
          float deposits;//sum of deposits received 
      };
       //Declare Variables
      Userinfo x; 
      int LIM = 6; //account number limit 
      char accNum[LIM];//account number of user
      int fee = 15; //fee for overdrawn accounts
      char c;       //sentinel value to end account number loop
      
      //Initialize the variables
      //First get the user account number, validate input using loop and strlen
      do{
        error:
        cout<<"Please enter your 5 digit account number and press enter"<<endl;
        cin>>accNum;          
        if (strlen(accNum)>=LIM){
        cout<<"An error has appeared, please try again"<<endl;
        cin.ignore();
        goto error;}  
        //Convert the cstring to a int for output
        x.aNum = atoi (accNum);
        cout<<"You entered "<<x.aNum<<endl;
        cout<<"Would you like to reenter your account number?"<<endl;
        cin.ignore(); cin.get(c);
      }while(tolower(c)== 'y');
      //Convert the character string to an integer
      //Get the starting balance
      cout<<"Enter in your balance from the beginning of the month"<<endl;
      cin>>x.bal; 
      
      //Get the amount of checks written by the user
      cout<<"Please Enter the amount of each check written this month"<<endl;
      cout<<"Enter 0 when you are finished entering checks"<<endl;
      float value; //user inputted value
      do{
        cout<<"$";
        cin>>value;
        x.checks +=value;
      }while(value != 0);
        
      //Get the amount of deposits received by the user  
      cout<<"Please Enter the amount of each deposit received this month"<<endl;
      cout<<"Enter 0 when you are finished entering deposits"<<endl;
      value = 0; //Reset the value variable
      do{
        cout<<"$";
        cin>>value;
        x.deposits +=value;
       }while(value != 0);
       
      //Calculate the new monthly balance 
      x.bal = (x.bal + x.deposits) - x.checks;
      //Output the results
      
      //If the user has overdrawn, let the user know of the 15 dollar fee
      if (x.bal<0){
          cout<<"You have overdrawn your account this month!"<<endl;
          cout<<"We have applied a $"<<fee<<" fee to your account"<<endl;
          cout<<showpoint<<setprecision(2)<<fixed<<"Account Balance: $"<<x.bal-fee<<endl;
      }
      //If the user has not overdrawn, output the balance
      else {
          cout<<"Your account balance for the month"<<endl;
          cout<<showpoint<<setprecision(2)<<fixed<<"Balance: $"<<x.bal<<endl;
      } 
      
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        //Declare Variables
        vector<Employee> curr; //vector of structures to hold current employee
        float gross; //Gross pay for all employees
        char c;
        int i =0;
        do{
         //Create a new instance of the employee structure
          curr.push_back(Employee());cin.ignore();
          cout<<"Employee Name: "; getline(cin,curr[i].name);
          _hrs:
            cout<<"Hours worked: "; cin>>curr[i].hrs;
            if (curr[i].hrs<0){cout<<"Cant have negative hours!"<<endl; 
            goto _hrs;}
          _rate:
            cout<<"Rate of Pay: "; cin>>curr[i].rtepy;
            if (curr[i].rtepy<0){cout<<"Cant have a negative rate of pay!"<<endl; 
            goto _rate;}
          
          //Determine if the employee has worked overtime 
          if (curr[i].hrs<=40) curr[i].total = curr[i].hrs * curr[i].rtepy;
          else if (curr[i].hrs>40 && curr[i].hrs<=50){
              curr[i].total = (curr[i].rtepy*40)+ ((curr[i].hrs-40)*(2*curr[i].rtepy));
          }else{curr[i].total = (curr[i].rtepy*40)+ (2*curr[i].rtepy * 10) 
                  + (curr[i].hrs-50)*(3*curr[i].rtepy);}
          
          //Output the employee check 
          cout<<showpoint<<fixed<<setprecision(2);
          cout<<"*****************************************************"<<endl;
          cout<<"Employee: "<<curr[i].name<<endl;
          cout<<"Hours worked: "<<curr[i].hrs<<endl;
          cout<<"Rate of Pay: $"<<curr[i].rtepy<<endl;
          cout<<"------------------------------------------------------"<<endl;
          cout<<"                    "<<"Gross Pay:   $"<<curr[i].total<<endl;
          cout<<"*****************************************************"<<endl;
          //add the employee gross pay to the gross overall pay
          gross += curr[i].total;
          cout<<"The Gross overall pay for all employees thus far is $"<<gross<<endl;
          //Determine if the user would like to enter more employees
          cout<<"Would you like to add another employee? Y/N"<<endl;
          cin.ignore(); cin.get(c); i++;
        }while(tolower(c) == 'y');
        
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
        //Declare variables
        char code[4];
        cin.ignore();
        
       _error: 
        bool digs = false;
        cout<<"Enter a 4 digit integer with digits (0-7)"<<endl;
        cin>>code;
        for(int i =0; i<5;i++){
            if(code[i] == '8' || code[i] == '9'){
                digs = true;
                break;
            }
        }
        if (strlen(code)!=4 || digs){
            cout<<"Error!4 digits are required and they "
                    "must be digits 0-7!"<<endl;
            goto _error;}
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}