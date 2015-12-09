/* 
 * File:   game.h
 * Author: Amul.bham
 *
 * Created on December 9, 2015, 12:14 AM
 */


#ifndef GAME_H
#define	GAME_H
#include "Deck.h"
#include "player.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

class game {
public:
    game();
    game(int n);
    void getInfo(player &);
    void disBord();
    game(const game& orig);
    virtual ~game();
private:
    vector<player> x;
    int numP;
    int cot;
};

#endif	/* GAME_H */

