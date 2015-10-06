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
#include <fstream>
//User Libraries

//Global Constants

//Function Prototypes
int cntvwls(char*);
int cntconst(char*);

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    int curLine;
    string line;
    string search; 
    
    ifstream name;
    name.open("test.txt");
    cout<<"Type the name you want to search (Type amul for example)"<<endl;
    cin>>search;
  if(name.is_open()){
      while(!name.eof()){
      getline(name,line);}
          if((curLine = line.find(search,0))!= string::npos){
              cout<<"The word has been found "<<search<<endl;
              }
          
      name.close();
      }
  else{
      cout<<"Could not open file"<<endl;
      }
    //Exit stage right!
    return 0;
    }
