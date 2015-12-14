/* 
 * File:   Deck.h
 * Author: Amul.bham
 * Purpose: The deck classes was responsible for all the dealings of 
 * the deck of cards used in the game. The idea was to wrap
 * all the complexity of creating a deck of cards, I really tried to make 
 * the class a individual meaning it can be applied to really any card game,
 * the drawCard function does it all, wraps up all the dealings of the deck in 
 * one function, prints out the cards, and returns a card value
 * The Class creates a vector of values 2-53 and then shuffles that vector
 *  - The card is drawn starting from value zero and then the variable is incremented
 * after each card draw
 * - Once the card number hits a certain limit, the deck is re shuffled automatically, 
 * displaying a message to the players so they know. 
 * - The name of each card is printed out as a string, and the value of the card
 * is returned back to the the caller for what ever purpose.
 *  -Ex: for blackjack, the card value is returned and added to the players
 * overall card total.
 *  
 * Created on December 8, 2015, 7:37 PM
 */

#ifndef DECK_H
#define	DECK_H
using namespace std;

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>

class Deck {
public:
    Deck();
    void shuffleCards();
    void makeDeck();
    void getFace();
    void getValue();
    int drawCard();
    void dispCards();
    Deck(const Deck& orig);
    virtual ~Deck();
private:
    /*Vector used to store values 2-53 to represent cards in a deck
     allowed for use of random_shuffle function and easier manipulation*/
    vector<int> deck;
    /*Card int used track the current card # of the card being drawn, it is
     incremented after each draw for the next card
     total stored the card value of card that was drawn, as the card # had no
     relevance to the actual value of the card*/
    int card,total,y;
    /*Face and Value used to store the string representations of the card that was drawn,
     they are then sent to the display cards function for output, kept separate from
     the value of the card itself as face cards were not represented as numbers*/
    string face,value;
    //Static const used to represent the number of cards in a deck, ensured that this value did not change
    static const int tCards = 53;
    

};


#endif	/* DECK_H */

