/* 
 * File:   main.cpp
 * Author: Amul Bham
 * Created on October 10, 2015, 2:27 PM
 * Purpose: Create a program that converts
 * Celsius to Farhrenheit
 */
 
using namespace std;

//System Libraries
#include <iostream> //Input/Output stream Library
#include <cstring>
#include <string>

//User Libraries

//Global Constants

//Function Prototypes
int cntWrds(char*, int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 30;
    char wrds[SIZE];
    int num;
    //Initialize Variables
    cout<<"Enter a string to be counted"<<endl;
    cin.getline(wrds,SIZE);
    //Call the count words function and set it to a new variable num
    num = cntWrds(wrds,SIZE);
    //Output the results to the user, pass the string to the count words funciton 
    cout<<"Your string has "<<num<<" words"<<endl;
    
    //Exit stage right!
    return 0;
    }

int cntWrds(char* wrds, int size ){
    //Declare variables
    int count = 0; //integer for the word count
    //Loop to count the number of spaces, for every space, 
    //Increment the count by 1 for each word until it hit the null terminator
    while (*wrds != '\0'){
        //Find through the first word till it hits a blank character
        while (*wrds != '\0' && isblank(*wrds)){
        wrds++;
        }
        //Then count the word when it reaches a blank
        if(*wrds != '\0'){
        count++;
        }
    //After the word is counted, the char string must be moved to the next word
        while (*wrds != '\0' && !isblank(*wrds)) 
        {
        wrds++;
        }
  }
    //Return the count back to the main function 
    return count; 
    
    }