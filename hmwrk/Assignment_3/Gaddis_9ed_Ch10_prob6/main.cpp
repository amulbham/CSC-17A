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
#include <cstring>
#include <string>
#include <cctype>

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
    int both;
    
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
    
    switch(choice){
        case 1:cntvwls(wrds);break;
        case 2:cntconst(wrds);break;
        case 3:both = cntconst(wrds) + cntvwls(wrds);
        case 4:cout<<endl<<"Enter a String"<<endl;
            cin>>wrds; break;
        case 5:break;  
        }
    }while(choice !=5);
    
    //Exit stage right!
    return 0;
    }

int cntvwls(char* wrds){
    int vowels = 0;
	while(*wrds){
		if(strspn(wrds, "aeiou"))
			vowels++;
		wrds++;
	}

	cout<<"Your string has "<<vowels<<" vowels"<<endl;        
return vowels;        
        }
        
int cntconst(char* wrds){
    int cons = 0;

	while(*wrds){
		if(!strspn(wrds, "aeiou") & !strspn(wrds," "))
			cons++;
		wrds++;
	}

	cout<<"Your string has "<<cons<<" constants"<<endl;      
return cons;          
        }