/* 
 * File:   player.cpp
 * Author: Amul.bham
 * 
 * Created on December 8, 2015, 9:12 PM
 */

#include "player.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;
player::player() {
    cardTot =0;
    begBal =0;
    binN =0;
    bet = 0;
    ace = false;
    status = false;
    
}

player::player(const player& orig) {
}

player::~player() {
}

