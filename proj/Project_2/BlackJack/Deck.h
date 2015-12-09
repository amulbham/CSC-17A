/* 
 * File:   Deck.h
 * Author: Amul.bham
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

class Deck {
public:
    Deck();
    void shuffleCards();
    void makeDeck();
    int valueCards();
    Deck(const Deck& orig);
    virtual ~Deck();
private:
    vector<int> deck;
    int card;
    string face,value;
    const int tCards = 52;
    

};

#endif	/* DECK_H */

