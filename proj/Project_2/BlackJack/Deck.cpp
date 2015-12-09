/* 
 * File:   Deck.cpp
 * Author: Amul.bham
 * 
 * Created on December 8, 2015, 7:37 PM
 */

#include "Deck.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

Deck::Deck() {
    card = 0;
    makeDeck();
    shuffleCards();
}

Deck::makeDeck(){
    for(int x=0;x <tCards ;x++){
        deck.push_back(x+2);
        }
}

Deck::shuffleCards(){
    srand (time(0));
    random_shuffle(deck.begin(),deck.end(),rand());
}

Deck::valueCards(){}

Deck::Deck(const Deck& orig) {
}

Deck::~Deck() {
}

