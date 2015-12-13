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

dealer::dealer() {
    cardTot = 0;
    status = 1;
    ace = false;
}

void dealer::setCardT(int card){
    if (card >= 14){
        if (giveTotal()<= 10){ card = 11; setAce(1);}
        else{ card = 1; setAce(0);}
    }else if (card>10 && card < 14){
        card = 10;
    }
    addTotal(card);
}
void dealer::reset(){
    cardTot = 0;
    status = 1;
    ace = false;
}
void dealer::setStat(){
    if (cardTot < 17) {status = 1;} 
    else if (cardTot >=17 && cardTot <= 21){status = 2;}
    else if (cardTot > 21) {status = 3; } 
    
}
void dealer::addTotal(int card){
    cardTot += card;
    if (giveAce()==true && cardTot > 21) cardTot -=10;
    
    setStat();
}
dealer::dealer(const dealer& orig) {
}

dealer::~dealer() {
}

