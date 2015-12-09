/* 
 * File:   main.cpp
 * Author: Amul Bham (Project 1)
 * Purpose: To play Blackjack against 
 * A.I. implementing methods learned from
 * chapters 9-16.
 * Created on October 17, 2015, 2:42 PM
 */
//System Libraries
#include <iostream>     
#include <algorithm>    
#include <ctime>        
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

//Global Constants

//User Libraries
#include "Deck.h"
#include "player.h"
#include "game.h"

//Function Prototypes
void displayGreeting(); //function for greeting player

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
     int p;

     
    cout<<"                 Casino Bham's BlackJack"<<endl;
    game.disBord;
     //Determine how many players are going to play
    _np:
     cout<<"How many players would like to play? (Up to 4 total)"<<endl;
     cin>>p;
     
     if (p<1 || p>4) {cout<<"Invalid players!"<<endl; goto _np;}
     
     game blackJack(p);
     blackJack.disBord();

     
     
 return 0;    
}