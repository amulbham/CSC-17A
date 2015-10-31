/* 
 * File:   main.cpp
 * Author: Amul.bham
 * Purpose: Midterm CSC-17A
 *
 * Created on October 27, 2015, 5:09 PM
 */

//Library includes Here!!!
#include <iostream>     
#include <algorithm>    
#include <cstdlib>
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
            for(int j = 0; j<curr.size();j++)
            { cout<<endl<<endl<<showpoint<<fixed<<setprecision(2);
          cout<<"*****************************************************"<<endl;
          cout<<"Employee: "<<curr[j].name<<endl;
          cout<<"Hours worked: "<<curr[j].hrs<<endl;
          cout<<"Rate of Pay: $"<<curr[j].rtepy<<endl;
          cout<<"------------------------------------------------------"<<endl;
          cout<<"                    "<<"Gross Pay:   $"<<curr[j].total<<endl;
          cout<<"*****************************************************"<<endl;
            cout<<endl;}
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
        vector <int> arr; //vector used to store the inputted values
        int num;         //User input for how many values they would like to calc for. 
        statsResult *x;  //Structure to hold the information produced in function
        
        //Initialize the variables
        cout<<"How many input would you like to fill in the array?"<<endl;
        cin>>num;
        cout<<"Please enter the array values:"<<endl;
        for(int i = 0; i<num;i++){
            cout<<"Value "<<i+1<<":";
            arr.push_back(int());
            cin>>arr[i];
        }
        //Set the pointer memory = the pointer created in the function to a structure
        x = avgMedMode (arr,arr.size());
        //Send the structure to the print function to output the results
        printStat(*x);
        
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
        //Declare variables
        char code[4];   //4 digit intger
        char x0[1],y2[1];//Used for temp swaps
        int num[4];     //Stores the encrypted/decrypted number
        char a;         //Used to end the program 
        int y;          //Determines if user would like to run program again
       _error: 
            
        bool digs = false; //Sets a flag if the user has made an input error
        cout<<"Enter a 4 digit integer with digits (0-7)"<<endl;
        cin>>code;
        //Check for input errors and proper lengthm
        //If error occurs, goto the input again
        for(int i =0; i<5;i++){
            if(code[i] == '8' || code[i] == '9'){
                digs = true;
                break;
            }
        }
        //Warn the user they have made an error
        if (strlen(code)!=4 || digs){
            cout<<"Error!4 digits are required and they "
                    "must be digits 0-7!"<<endl;
            goto _error;}
        //Determine if the user is encrypting or decrypting 
        _input:
        cout<<"Would you like to encrypt or decrypt? 1 or 2"<<endl;
        cin>>y;
        switch(y){
            case 1:   { 
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
        num[i] = num[i]% 8;
        cout<<num[i];
        }
        break;
        cout<<endl;
        }
            //If the user wants to decrypt a number
            case 2:{
                //Swap the digits back to the proper place
        x0[0] = code[0];
        y2[0] = code[2];
        code[0] = code[1];
        code[1] = x0[0];
        code[2] =  code[3];
        code[3] = y2[0];
        
        //Output the results 
        cout<<"Your decrypted 4 digit number is : ";
        for (int i = 0;i<4;i++){
        num[i] = code[i]-'0';
        num[i] = (num[i] + 8 - 5) %8;
        
        cout<<num[i];}
        break;
        }
            default: goto _input;    
            
        }
        //Determine if the user would like to run the program again 
        cout<<endl;
        cout<<"Would you like to run the program again? y/n"<<endl;
        cin.ignore(); cin.get(a);
        if (tolower(a) == 'y') goto _error;
        
       
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
        //Declare Variables
        int a =1; unsigned int a1 = 1;
        short int b = 1; unsigned short b1 = 1;
        long int c = 1; unsigned long int c1 = 1;
        float d =1;    
        double e = 1;
        long long int f =1; unsigned long long int f1 =1;
        int count =0;
        
        for(int i=1;b != 0;i++){
            count ++;
            b =b*i;
         }
        count--;
        b = 1;
        for(int i=1;i<=17;i++){
         b =b*i;
         }
        //Output the results
        cout<<"Int: 33"<<endl;
        cout<<"Unsigned Int: 33"<<endl;
        cout<<"Short Int: 17"<<endl;
        cout<<"Unsigned Short: 17"<<endl;
        cout<<"Long Int: 65"<<endl;
        cout<<"Unsigned Long Int: 65"<<endl;
        cout<<"Float: 34"<<endl;
        cout<<"Double: 170"<<endl;
        cout<<"Long Long Int: 65"<<endl;
        cout<<"Unsigned Long Long Int: 65"<<endl<<endl;
        
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
        cout<<"Part A:"<<endl;
        cout<<"2.125: "<<endl;
        cout<<"Binary: 10.001\n"
                "Hex: 2.2\n"
                "Octal: 2.1\n"
                "Float Hex: C0080000"<<endl<<endl;
        cout<<".06640625: "<<endl;
        cout<<"Binary: 0.00010001\n"
                "Hex: 0.000011\n"
                "Octal: 0.042\n"
                "Float Hex: 3D880000"<<endl<<endl;
        
        cout<<"Part B: Convert Float to Decimal"<<endl;
        cout<<"46666601: 14,745"<<endl;
        cout<<"46666602: 14,746"<<endl;
        cout<<"B9999AFE: -1.200042486 * 2^-12 or -0.0002929791"<<endl;
        
        
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
    vector<int> m;          //Temp vector to store the modes

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
   //Assign the new values to the structures
    z->maxFreq = freq;
    z->nModes = m.size();
    //Create a new dynamic array with the number of modes
    z->mode = new int[m.size()];
    //Assign the modes to the new array using a loop
    for(int i = 0; i<m.size();i++){
    z->mode[i] = m[i];
    }
    //Return the pointer to the structure back to the main function 
    return z;


} 


void printStat(struct statsResult y){
    //Output the results of the array
    cout<<showpoint<<fixed<<setprecision(2)<<endl<<endl;
    cout<<"Mean: "<<y.avg<<endl;
    cout<<"Median: "<<y.median<<endl;
    cout<<"Number of Modes: "<<y.nModes<<endl;
   //Loop through the new array to output all of its data 
    for(int i =0; i<y.nModes;i++){
    cout<<"Mode: "<<*(y.mode)<<endl;
    y.mode++;
    }
    cout<<"Mode Frequency: "<<y.maxFreq<<endl;
    
}