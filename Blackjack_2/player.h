/* 
 * File:   player.h
 * Author: Amul.bham
 * Purpose: I needed a class to track all the important player information
 * for each player, throughout the game, keeping everything organized.
 *
 * As this class mainly stores information, most functions have no purpose other
 * than to return the called upon player variable or set a player variable to a 
 * new value
 * 
 * The player class is derived from the dealer class as they share certain
 * common characteristics such as having to have a card total variable and 
 * other statuses that needed to be tracked such as receiving an ace, so 
 * it made sense to use the dealer class at a template for my player class, 
 * adding specific variables for the player class, such as balance. 
 * 
 * I also made it so the player class ACT for ONE player and represents the 
 * dealings of ONE player, thus a container must be used such as a vector
 * for multiple players, I found this to be must easier and to simply loop
 * through each player instance than to create specific functions for multiple
 * players
 * 
 * From this class, the only player information stored in the file for 
 * later games are the name, balance, and binary number position, everything else
 * is created new from game to game.
 * 
 * Used mostly in line functions as the functions were short and to aid in speed
 * Created on December 8, 2015, 9:12 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include "dealer.h"

using namespace std;

//Inherits all the functions and protected members of dealer class
class player : public dealer {
public:
    //Sets binary number position
    void setBin(int n){binN = n;}
    //Sets all values to 0, and new player by default when a player class
    //is created
    player():dealer(){
        bal = 0;
        bet = 0;
        newP = true;
        setBin(50);
    }
    //Sets the balance of the player
    void setBal(long int b){bal = b;}
    //Sets the bet of the player
    void setBet(long int c){bet = c;}
    //Sets the status, overrides the dealer setStat function
    void setStat();
    //Used to manually set the status (used as a check)
    void setStat(int num){status = num;} 
    //new or returning? Determines how the program will write data to file at end
    void setNew(int num){if (num == 0) newP = true; else newP = false;}
    //give the status of the player
    bool giveNew(){return newP;}
    //win? add the bet, loss means you lose bet
    void win(){bal +=bet;}
    void loss(){bal -=bet;}
    void reset();
    //return the balance to the calling object
    long int giveBal(){return bal;}
    //return the binary position of the player, for reading and writing
    int givePos(){return binN;}
    player(const player& orig);
    virtual ~player();
    char name[25];
private:
    //Stores the balance of the player
    long int bal;
    //stores the bet of the player
    long int bet;
    //stores the binary position in file of the player
    int binN;
    //TRUE = new player, FALSE = returning player
    bool newP;
};

#endif	/* PLAYER_H */

