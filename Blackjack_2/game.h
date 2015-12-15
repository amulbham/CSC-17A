/* 
 * File:   game.h
 * Author: Amul.bham
 *Purpose: The Main Purpose of this class was to control the game flow 
 * and logic of the game of BlackJack. This allowed my main function to focus on
 * the more abstract dealings of the program such as guiding which 
 * part of the game is to be executed first, while the game class
 * handled all the minor details and logic points involved in each 
 * part of the game. 
 * - In the game class, their lies a vector of player classes and a
 * instance of a deck class which I decided to aggregate into the game class
 * as any instance of a blackJack game will have to have players and a deck
 * of cards, therefore it was more logical to define the players within
 * the class based on how many players are playing for that given session
 * 
 * Aggregation Logic :
 * - A game of blackjack has -> players 
 * has a -> deck of cards 
 * and a -> dealer
 * 
 * - By allowing my main to control the higher abstract game flow, the game 
 * class controlled how each class interacted with each other and passed
 * values of each player to the different parts of the game. The main 
 * was used to control what parts of the black jack game were to be executed
 * in what order. 
 * 
 * - This kept the main as sort of a make file in that it simply controlled 
 * what parts of the game class to execute, this made it so in the future, 
 * I could add other game classes and use the main again to control that game 
 * as well, therefore allowing players to select which game they would want to play
 * from a menu in main.
 * 
 * Created on December 9, 2015, 12:14 AM
 */


#ifndef GAME_H
#define	GAME_H

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include "Deck.h"
#include "player.h"
#include "dealer.h"

using namespace std;

/*I created a temp structure as a means to temporarily store each players 
 crucial information, taken from each players instance of player
 * in the x container, and then write it into the player.txt as binary data
 * (Classes cannot be written into file as binary)
 * And Also to store the information from the player.txt for reading out
 * to the player at the start of the game
 */
   struct play_info{
       //Crucial information includes player name, their balance, and their
       //binary poistion in the file
        char name[25];
        long int bal;
        int bN;
    };
class blackJack {
public:
    blackJack();
    blackJack(int n);
    //Descriptions for all functions can be found in the .cpp file 
    void disBord();
    void disRules();
    void checkWinLoss();
    void setBets();
    void hitORstay();
    void checkWinner();
    void showResults();
    void dealCards();
    void dealerHand();
    void newHand();
    blackJack(const blackJack& orig);
    virtual ~blackJack();
    //create a player_info fstream to store for reading and writing our data
    fstream player_info;
    //Instance of the structure defined above
    play_info temp;
    void getInfo(player &);
    void writeInfo();

private:
    dealer dealer;  //instance of 1 dealer object for the game
    vector<player> x; //Container of player objects, each representing a player
    Deck deck;      //1 deck is object is required for the game 
    int numP;       //holds the number of players
    int cot;        
};

#endif	/* GAME_H */

