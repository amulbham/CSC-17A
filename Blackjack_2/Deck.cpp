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
    /*Let the players know any time the deck is re shuffled, 
     reset the card count to 0*/
    cout<<"Shuffling Cards..."<<endl<<endl;
    card= 0; //Reset the card number when the deck re shuffles
    srand (time(0)); //Random number seed for random_shuffle function
    
    /*Deck is shuffled using random_shuffle temp inside the algorithm
     standard library, this function only works on vectors, so it gave me 
     all the more reason to put the deck inside in vector*/
    random_shuffle(deck.begin(),deck.end());
}

void Deck::getFace(){
        /*Set the total as equal to the card, then the value of the card
         is determined from the total, this allowed the NUMBER value of the card
         to remain separate from the CARD NUMBER, I made all calculations
         on the total number and used the deck to represent where the card
         was in the deck*/
        total = deck[card];
        
        /*Determine suit and card total based on value of drawn card 2-53
          then I subtracted off a certain value depending on its range
         to make the values all a number between 2-13, this made it possible
         to use a switch to display the card name, so first the suit is determined
         based on its range in the deck, then the value is made a value between
         2-13, then a value is printed out alongside the suit*/
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
    /*Function used purely to display the name and suit of each 
     card that is drawn, since they are not suppose to be bound to any thing
     in real life, that was how I made my function, display the card
     return only what the player needs to know, which is the card value*/
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

