/* 
 * File:   main.cpp
 * Author: Amul Bham
 * Created on October 10, 2015, 2:27 PM
 * Purpose:Count the Number of words
 * in a user inputted C-String
 */
 
using namespace std;

//System Libraries
#include <iostream> //Input/Output stream Library
#include <cstring>  //to format the character tolower
#include <string>   
#include <cctype>   //to use the string span function

//User Libraries

//Global Constants

//Function Prototypes
int cntvwls(char*);
int cntconst(char*);

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 50;
    char wrds[SIZE];
    int choice;
    
   //Ask the user to enter a string value 
    cout<<endl<<"Enter a String"<<endl;
    cin.getline(wrds,SIZE);
    for(int i=0;i<SIZE;i++){
        tolower(wrds[i]);
        }
    //Provide a Menu to the user
 do{ 
    cout<<"Program Menu - Please Select an Option below"<<endl;
    cout<<"1) Count the number of vowels in the string\n"
    "2) Count the number of consonants in the string\n"
    "3) Count both the vowels and consonants in the string\n"
    "4) Enter another string\n"
    "5) Exit the program"<<endl;
    cin>>choice;
    //Use a switch to create a menu for the user
    switch(choice){
        case 1:cout<<"Your string has "<<cntvwls(wrds)<<" vowels"<<endl;break;
        case 2:cout<<"Your string has "<<cntconst(wrds)<<" constants"<<endl;break;
        case 3:cout<<cntconst(wrds) + cntvwls(wrds)<<" of both"<<endl;break;
        case 4:cout<<endl<<"Enter a String"<<endl;
            cin>>wrds; break;
        case 5:break;  
        }
    }while(choice !=5);
    
    //Exit stage right!
    return 0;
    }

//Function used to count the vowels
int cntvwls(char* wrds){
    int vowels = 0;
	while(*wrds){
		if(strspn(wrds, "aeiou"))
			vowels++;
		wrds++;
	}
    //Return the vowels back to the main function 
return vowels;        
        }
//Function used to count the constants
int cntconst(char* wrds){
    int cons = 0;
    //While the characer is not a vowels or a space, then increment the constants
	while(*wrds){
		if(!strspn(wrds, "aeiou") & !strspn(wrds," "))
			cons++;
		wrds++;
	}
    //Return the constants back to main. 
	    
return cons;          
        }