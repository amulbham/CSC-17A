/* 
 * File:   dealer.h
 * Author: Amul.bham
 * Purpose: To store and provide access to all the important dealer
 * information needed for a game
 * Created on December 12, 2015, 7:51 PM
 */
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

#ifndef DEALER_H
#define	DEALER_H

/*Used to represent the dealer of a card game, only needed mutator and 
accessor functions, and variables to store dealer information 
in regards to the game being played (ex :card total for blackjack)
 */
class dealer {
public:
    dealer();
    //Set the ace value to true or false
    void setAce(int num){
        if (num == 0) ace = false;
        else ace = true;
    }
    virtual void setStat();
    void setCardT(int card);
    void addTotal(int card);
    virtual void setStat(int num){status = num;} 
    bool giveAce() {return ace;}
    int giveTotal(){return cardTot;}
    int giveStat(){return status;}
    void reset();
    dealer(const dealer& orig);
    virtual ~dealer();
protected:
    //used to track the card total of the player throughout the game
    int cardTot;
    
    /*variable status KEY: Determines how the player is dealt with at 
     * each point in the game
     status = 1 => player is under 21 and has the option of continuing to hit
     * , if they are finished their status will change to 2
     status = 2 => player is finished with the hand or hit a 21 
     status = 3 - player has lost the hand and has no chance of winning
     status = 4 -> player has tied the dealer, bet given back to player
     status = 5 -> Player has beat the dealer and won!*/
    int status;
    
    //TRUE = ACE, FALSE = NO ACE
    //Crucial as ace in blackjack as multiple meaning depending on the card total
    //of the player, thus must be tracked for each player, but reset for each hand
    bool ace;

};

#endif	/* DEALER_H */

