/*Name: Amul Bham
 11/17/2015
 Purpose: Menu for Assignment 5 - Classes and Objects*/


//Library includes Here!!!
#include <iostream>
#include <cstring>
#include <vector>
#include "date.h"
#include "personal.h"
#include "RetailItem.h"

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
        string x; //Dummy variable used to store the string values of the objects
        int y; //Dummy variable used to fill the age 
        char z; //Sentinel value used to end the loops
        int i =0; //int to keep track of the records of users 
        vector<personal> user;
        //Get personal information from the user
        do{
        //Create a new instance of the personal object, store in the user vector    
        user.push_back (personal());
        cin.ignore();
        cout<<"Please enter your name: ";getline(cin,x);
        user[i].setName(x);
        cout<<"\nPlease enter your address: "; getline(cin,x);
        user[i].setAdd(x);
        cout<<"\nPlease enter your age: "; cin>>y;
        cin.ignore();
        user[i].setAge(y);
        cout<<"\nPlease enter your phone number: "; getline(cin,x);
        user[i].setPhone(x);
        i++; //Increment to the next user in case new data in entered
        cout<<"\nWould you like to enter another user?"<<endl;
        cin.get(z); 
        //If the user would like to enter a new record, create a new instance of
        //user and loop back to the questions 
        }while(tolower(z)== 'y');
        
        //Output the relevant user information based on the user choice 
        do{
         //Restart point incase the user enters an invalid option 
        _restart:
        //Determine which user information they would like to see 
        cout<<"Which user information would you like to see? (1-3)"<<endl;
        cin>>i;
        if (i<1 || i>user.size() ) {cout<<"No such user exits!Enter a valid user!"<<endl; goto _restart;}
        i-=1; //Subtract 1, as the data begins at 0
        user[i].getName();
        user[i].getAge();
        user[i].getPhone();
        user[i].getAdd();
        //Determine if the user would like to view a new record 
        cout<<"Would you to view someone else? y/n"<<endl;
        cin.ignore(); cin.get(z);
        }while(tolower(z) == 'y');
}

void problem3(){
        cout<<"In problem # 5"<<endl<<endl;
        //Declare the variables
        float pri; //stores the price of an item
        string d;   //stores the description of an item 
        int stock; //stores the number of stock of an item 
        char c;    //determines if user wants to continue
        vector<RetailItem> item; //stores each instance of each item 
        
        //Initialize the instances of the retail item vector
        do{
            //Create a new item and store as a retail item class 
            cout<<"Please enter a brief description of the product"<<endl;
            cin.ignore();
            getline(cin,d);
            cout<<"Please enter the units currently on hand: "; cin>>stock;
            cout<<"Please enter the retail price: $"; cin>>pri;
            //Setup the constructor for the RetailItem instance
            item.push_back(RetailItem(d,stock,pri));
             //Loop back if the user would like to enter a new product 
            cout<<"\nWould you like to enter another product? y/n"<<endl;
            cin.ignore(); cin.get(c);
        }while(tolower(c) == 'y');
        do{
        _again:
        int i = 0;
        cout<<"Which item information would you like to see? Type an item #"<<endl;
        cin>>i;
        if (i<1 || i>item.size() || isalpha(i) ) {cout<<"Item information does not exist!"<<endl; goto _again;}
        i-=1; //Subtract 1, as the data begins at 0
        cout<<"Description: "<<endl<<item[i].getDesc()<<endl;
        cout<<"Price: "<<item[i].getPrice()<<endl;
        cout<<"Units on hand: "<<item[i].getUnits()<<endl;
        //Determine if the user would like to view a new record 
        cout<<"Would you to view another item? y/n"<<endl;
        cin.ignore(); cin.get(c);
        }while(tolower(c) == 'y');
        
        
}

void problem4(){
        cout<<"In problem # 6"<<endl<<endl;
}


void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}