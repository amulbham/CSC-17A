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
#include <cstring>

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
     char agn;

     
    cout<<"                 Casino Bham's BlackJack"<<endl<<endl;

    //Determine how many players are going to play
    _np:
     cout<<"How many players would like to play? (Up to 4 total)"<<endl;
     cin>>p;
     
     if (p<1 || p>4) {cout<<"Invalid players!"<<endl; goto _np;}
     /*Determine for each player if they are returning or a new player
      If they are returning, read out the name and balance in memory of the player
      if they are new, get the player name, and player buy in amount*/
     blackJack game(p);
     do{
     game.disBord();
     /*Get the bets for the hand from each player, keep track of the bet amount
     , starting balance, and if the player has overdrawn and needs to buy in again*/
     game.setBets();
     game.disBord();
     //Deal the first two cards to the player
     game.firstTwo();
     game.checkWinLoss();
     game.disBord();
     //Deal the first card of the dealer
     game.dealOne(1);
     game.disBord();
     //Deal the rest of the player hands
    game.hitORstay();
    game.checkWinLoss(); 
    game.disBord();
    
    //Deal the rest of the dealers hand
    game.dealOne(2);
    game.disBord();
    
    
    //Determine the winner of the hand
    game.checkWinner();
    
    //Determine the new balances based on winners
    game.calcBal();
    
    //Output the results of the hand to the user 
    game.showResults();
    game.disBord();
    
    cout<<"Would you like to play another hand? Y/N"<<endl;
     cin.ignore(); cin.get(agn); 
     }while(tolower(agn) == 'y');

     
     
     
 return 0;    
}