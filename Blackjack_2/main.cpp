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
#include "dealer.h"

//Function Prototypes
//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    
    /*Both of these variables were used as outside switch variables
     to trigger what happens to the other classes and functions, 
     if the player is playing with others, a vector is created, 
     agn is used to control the game loop, which starts at the beginning of 
     each hand and ends when agn turns to 'no'*/
     int p;
     char agn;

     //Display a greeting to the user
    cout<<"                 Casino Bham's BlackJack"<<endl<<endl;

    /*Determine how many players are going to play, from here
     a vector is created with p players of the player class
     ex: p = 3; 3 instances of player class are created and place in a vector*/
    do{
     cout<<"How many players would like to play? (Up to 4 total)"<<endl;
     cin>>p;
     //Ensure the amount of players is not over 4 as it can get hectic on one screen
     if (p<1 || p>4) {cout<<"Invalid players!"<<endl;}
    }while(p<1 || p>4);
     /*Create a new instance of the blackJack class, this class control
      all of the game flow of blackJack game for the user, meaning the player
      and deck classes are totally separate and stand alone, in the future more
      games can be added here by simply creating a new class for the game and
      adding a menu here for each game*/
     blackJack blkJck(p);
     
     
     /*Game Loop starts here -> from here is where each new hand starts,
      the players have the choice to leave after each hand, if they do want to 
      play again, their card totals are reset, however their names and 
      binary file positions are maintained as that was done in the 
      creation of the blackJack object*/
     do{
     blkJck.disBord();
     /*Get the bets for the hand from each player, keep track of the bet amount
     , starting balance, and if the player has overdrawn and needs to buy in again*/
     blkJck.setBets();
     blkJck.disBord();
     /*The first cards are dealt to each player,the drawnCard function of the 
      * card class is called, a card is printed out, and its value is
      * passed back and added to the players overall card total for 
      * the hand, if the player has any significant hands (blackjacks, busts, etc) 
      * they are displayed after they are encountered.
      each players hand has been displayed*/
     blkJck.dealCards();
     
     blkJck.disBord(); //<- this function just prints out a standard border
 
     
     /*At this point, the players must decide if they want to hit or stay
      depending on their current card value, if a player decides to hit or stay,
      each player is given the turn and can continue till they decide to stay,
      go over 21 or hit a 21, at which point it begins the next players turn
      Status is tracked after each players hand is finished, meaning
      if they lose they are marked as a loss, if they hit a 21 they are marked
      * as a possible win,if they decide to stay under 21 they are marked for compare */
    blkJck.hitORstay();
    blkJck.disBord();
    
    /*After the hit stay portion of the hand, assuming that at least 1 of the players
     has not 'busted', the rest of the dealer hand is dealt till the dealer
     hit a value of 17 of greater All the cards were displayed and valued
     using the drawn card function in the deck class*/
    blkJck.dealerHand();
    blkJck.disBord();
    
    /*Using the status of each player, and the dealer, which was tracked
     after each card draw, a final comparison is held between each player
     and the dealer card value, So for example if the dealer had a 21, 
     any player who is not marked with a status of '21' automatically
     * loses, and the players who do have a 21 are marked as a tie. After this
     * the balance of each player is recalculated based on the status of 
     * their hand, tie = no money loss, loss = loss of bet etc.  */
    blkJck.checkWinner();
    
    /*The results of the hand are displayed in a overall report at the end
     of each hand and a recalculated balance is printed out for each 
     player, from here they can decide to play another hand or end the game*/
    blkJck.showResults();
    blkJck.disBord();
    /*The players can now decide, after seeing their results, if they want to 
     play again*/
    cout<<"Would you like to play another hand? Y/N"<<endl; 
    cin.get(agn); 
    /*If the players do want to play a new hand, then the game loops back to the start
     of the doWhile loop, all the card values and totals are reset for each player*/
     if (tolower(agn) == 'y') blkJck.newHand();// <- Resets each players hand
     }while(tolower(agn) == 'y');
     
     /*If the players decide they are finished playing, each players information
     including their name and balance are stored in a file, this allows each player
     to have their own separate account in the game and can maintain
     their own balance in the game. If they already have a spot on the binary
     file, their spot is overwritten using random access file entry, and overriding
     the spot on file that represents their binary number, if they are a new player
     their information is appended to the file in a new spot and a binary number
     representing their spot on the file is assigned to the new player*/
     blkJck.writeInfo();
     
     //Exit Stage Right!
 return 0;    
}