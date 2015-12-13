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
#include "dealer.h"
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
    void hitORstay();
    void checkWinner();
    void showResults();
    void dealCards();
    void dealerHand();
    void newHand();
    void writeInfo(player &);
    blackJack(const blackJack& orig);
    virtual ~blackJack();
private:
    dealer dealer;
    vector<player> x;
    Deck deck;
    int numP;
    int cot;
};



#endif	/* GAME_H */

