/* 
 * File:   game.h
 * Author: Amul.bham
 *
 * Created on December 9, 2015, 12:14 AM
 */


#ifndef GAME_H
#define	GAME_H

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include "Deck.h"
#include "player.h"
using namespace std;

class blackJack {
public:
    blackJack();
    blackJack(int n);
    void getInfo(player &);
    void disBord();
    void disRules();
    void checkWinLoss();
    void setBets();
    void firstTwo();
    void hitORstay();
    void dealOne(int);
    struct dealer {
        int total;
        string status;
        bool ace;
    };
    void setDeal(int t);
    blackJack(const blackJack& orig);
    virtual ~blackJack();
private:
    vector<player> x;
    Deck deck;
    int numP;
    int cot;
};

#endif	/* GAME_H */

