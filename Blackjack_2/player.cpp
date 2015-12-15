/* 
 * File:   player.cpp
 * Author: Amul.bham
 * 
 * Created on December 8, 2015, 9:12 PM
 */

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>

#include "player.h"
using namespace std;

/*Used to check the card value of the player after each card draw, 
 and then determine the status of the player for the next card draw
 
 Then the status is used by the calling object to determine if the player
 has lost, skip the next card draw, hit a black jack, etc
 
 -> this made it easier to determine which players needed to be skipped in the
 game flow*/
void player::setStat(){
    if (cardTot < 21) status = 1; //continue compare
    else if (cardTot == 21) status = 2; //finished 
    else if (cardTot > 21) status = 3; // lost
}

/*reset() -> overrides the dealer reset function as it has to reset
 additional player values after each hand such as the bet,
 called to reset player variables that are required to be a certain value
 at the start of each hand
 * for Ex: card total MUST be reset for each player
 * or the card total would be carried over into the next hand! */
void player::reset(){
    cardTot = 0;
    status = 1;
    ace = false;
    bet = 0;
}

player::player(const player& orig) {
}

player::~player() {
}

