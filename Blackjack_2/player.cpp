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

void player::setStat(){
    if (cardTot < 21) status = 1; //continue compare
    else if (cardTot == 21) status = 2; //finished 
    else if (cardTot > 21) status = 3; // lost
}

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

