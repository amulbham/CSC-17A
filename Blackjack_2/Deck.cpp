/* 
 * File:   Deck.cpp
 * Author: Amul.bham
 * 
 * Created on December 8, 2015, 7:37 PM
 */
using namespace std;


#include <vector>
#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <string>
#include <fstream>
#include "Deck.h"


Deck::Deck() {
    card = 0;
    face = "";
    value = "";
    total = 0;
    //Create the deck of card as soon as a deck object is created
    makeDeck();
}

void Deck::makeDeck(){
    //Initialize a vector with values 2-53 to represent each card in a 52 card deck
    for(y=2;deck.size() < tCards ;y++){
        deck.push_back(y);
        }
    //After creating a array of 2-53, send to function to random shuffle the cards
        shuffleCards();
}

int Deck::drawCard(){
    /*Re shuffle the cards only if the card count goes over 30, this 
      allows the game to not be predictive, also let the players know 
      so that its fair and the players are aware a new deck is being used*/
     if (card>30) {shuffleCards();} 
     
    //Reset the total prior to each new card drawn
    total = 0;
    
    //Draw a card from deck and first determine the face and the numerical value
       getFace();
       
    //Then the numerical value of the card must be translated to a string   
       getValue();
       
    //Display the drawn card for the user   
       dispCards();
       
        /*Return the player card back to the player,increment to the next card
         this makes it so the next card is ready to be drawn, the total is returned
         so that an overall card total can be tracked for each player*/
        card++;
        return total;

}

void Deck::shuffleCards(){
    cout<<"\nShuffling Cards..."<<endl;
    srand (time(0));
    random_shuffle(deck.begin(),deck.end());
}

void Deck::getFace(){
        //Set the total to be returned equal to the current card value
        total = deck[card];
        
        //Determine suit and card total based on value of drawn card 2-53
          if (deck[card]<=14){ 
              face = "Hearts";
          }else if (deck[card]>14 &&deck[card]<=27){
              total -= 13; 
              face = "Diamonds";
          }else if (deck[card]>27 && deck[card]<=40){
              total -= 26; 
              face = "Cloves";
          }else if (deck[card]>40){
              total -=39;
              face = "Spades";
            }
        
}

void Deck::dispCards(){
    cout<<value<<" of "<<face<<endl;
}

void Deck::getValue(){
    /*Use a switch to determine the string value of the card
     based on the numerical value*/
    switch(total){ 
            case 2:
                value="Two";
                break;
            case 3:
                value = "Three";
                break;   
            case 4:
                value = "Four";
                break;    
            case 5:
                value = "Five";
                break;
            case 6:
                value = "Six";
                break;
            case 7:
                 value = "Seven";
                break; 
            case 8:
                value = "Eight";
                break;
            case 9:
                value = "Nine";
                break;    
            case 10:
                value = "Ten";
                break; 
            case 11:
                value = "Jack";
                break; 
            case 12:
                value = "Queen";
                break; 
            case 13:
                value = "King";
                break;
            case 14: 
                value = "Ace";
                break;
    }

}
Deck::Deck(const Deck& orig) {
}

Deck::~Deck() {
}

