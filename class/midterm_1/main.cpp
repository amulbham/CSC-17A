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
//Problem 3
        struct statsResult
{
    float avg;
    float median;
    int  *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
//Global Constants Here!!!
vector<int> m;
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
statsResult *avgMedMode(vector<int> ,int); 
void printStat(struct statsResult);
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
        //Declare Variables
        vector <int> arr;
        int num;
        statsResult *x;
        
        //Initialize the variables
        cout<<"How many input would you like to fill in the array?"<<endl;
        cin>>num;
        cout<<"Please enter the array values:"<<endl;
        for(int i = 0; i<num;i++){
            cout<<"Value "<<i+1<<":";
            arr.push_back(int());
            cin>>arr[i];
        }
        x = avgMedMode (arr,arr.size());
        
        printStat(*x);
        
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
        //Declare variables
        char code[4];
        char x0[1],y2[1];
        int num[4];
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
        //Swap the digits of the number
        x0[0] = code[0];
        y2[0]= code[2];
        code[0] = code[1];
        code[1] = x0[0];
        code[2] = code[3];
        code[3] = y2[0];
        
        //Convert the string to an int, preform encryption, and output results
        cout<<"Your encrypted 4 digit number is : ";
        for (int i = 0;i<4;i++){
        num[i] = code[i]-'0';
        num[i]+=5;
        num[i]%=8;
        cout<<num[i];
        }
        cout<<endl;
       
        code[1] = code[0];
        code[0] = x0[0];
        code[3] =  code[2];
        code[2] = y2[0];
        
        //Determine if the user would like to decrypt
        cout<<"Your decrypted 4 digit number is : ";
        for (int i = 0;i<4;i++){
        num[i] = code[i]-'0';
        num[i]+=8;
        num[i]-=5;
        num[i]%=8;
        cout<<num[i];
        }
        cout<<endl;
           
       
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

//Problem 3
statsResult *avgMedMode(vector<int> arr,int num){
    //Declare Variables
    statsResult *z = new statsResult;  
    //calculate mean - add all values /2
        for(int i = 0; i<num;i++){
            z->avg += arr[i];
    }
    //divide by the total number of values to obtain mean
    z->avg /= num;
    
    
    //Median
    /*Put the data from array into a vector, this allows us to use the sort
    function to easily sort the list in ascending order*/
    sort(arr.begin(),arr.end()); //must be sorted for median 
    
    cout<<endl;
    //Determine if median is even or odd - then determine median number
    if (num  % 2 == 0){ //determines if even
      z->median = (arr[num / 2 - 1] + arr[num / 2]) / 2;
    }else{ //Odd number of values = size / 2;
      z->median = arr[num / 2];
    }
    
        //Use a loop to compare values of array
    int number = arr[0]; //compare number
    int count = 1;        //counter to track the frequency
    int freq = 1;           //frequency of the mode  
    for (int i=1; i<num; i++){
      if (arr[i] == number){ //if the numbers are the same
         count++; //add 1 to the frequency
      }else{
            if (count > freq) //if the new number has a greater freq.
            {     m.clear();
                  freq = count;
                  m.push_back(int(number));
            }else if (count == freq){
                  m.push_back(int(number));  
            }
            
           count = 1;       //reset the count for the next number
           number = arr[i]; //set the number = to the old one
  }
}
   
    z->maxFreq = freq;
    z->nModes = m.size();
    z->mode = new int[m.size()];
    for(int i = 0; i<m.size();i++){
    z->mode[i] = m[i];
    }
    return z;


} 


void printStat(struct statsResult y){
    cout<<"Mean: "<<y.avg<<endl;
    cout<<"Median: "<<y.median<<endl;
    for(int i =0; i<(sizeof y.mode / sizeof y.mode[0]);i++){
    cout<<"Mode: "<<*(y.mode)<<endl;
    y.mode++;
    }
    
    cout<<"Number of Modes: "<<y.nModes<<endl;
    cout<<"Mode Frequency: "<<y.maxFreq<<endl;
    
}