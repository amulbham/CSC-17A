/* 
 * File:   dealer.cpp
 * Author: Amul.bham
 * 
 * Created on December 12, 2015, 7:51 PM
 */

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include "dealer.h"

using namespace std;
//If a dealer is created, reset all values, make ace false
dealer::dealer() {
    cardTot = 0;
    status = 1;
    ace = false;
}
/*Used by the player class as well.
 ->Took the card value returned by the deck object, 
 ->normalizes the value in the case of a face card
 ->Checks for ace, if so, sets player ace variable to true
 ->Checks card value and assigns a value of 1 or 11 to the card
 ->After doing so, value is added to the overall player total*/
void dealer::setCardT(int card){
    //If ace, check value, set value for ace -> set status of ace
    //if 1 ace:false, if 11 ace::true
    if (card >= 14){
        if (giveTotal()<= 10){ card = 11; setAce(1);}
        else{ card = 1; setAce(0);}
    }else if (card>10 && card < 14){
        card = 10;
    }
    //After card is normalized, it is sent to addTotal to be added to the overall player total
    addTotal(card);
}

//Function created to resets important dealer variables whenever called
void dealer::reset(){
    cardTot = 0;
    status = 1;
    ace = false;
}
//Dealer has own logic for determining its status, as its goals are different
//than the players in some instances, so therefore this status function is
//overridden by the player class
void dealer::setStat(){
    if (cardTot < 17) {status = 1;} 
    else if (cardTot >=17 && cardTot <= 21){status = 2;}
    else if (cardTot > 21) {status = 3; } 
    
}
//After the total has finally be determined, it is added to the player total
void dealer::addTotal(int card){
    cardTot += card; //add the card value
    
    //Check for Ace! If ace is true, and value is over 21
    //Then the ace value is switched to a 1 instead of 11! 
    if (giveAce()==true && cardTot > 21) {
        cardTot -=10;
        ace = false;
    }
    //Set the status after adding total as the total is what dictates the status
    setStat();
}
dealer::dealer(const dealer& orig) {
}

dealer::~dealer() {
}

