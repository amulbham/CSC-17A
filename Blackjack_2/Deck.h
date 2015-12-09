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
    vector<int> deck;
    int card,total,y;
    string face,value;
    static const int tCards = 52;
    

};

#endif	/* DECK_H */

