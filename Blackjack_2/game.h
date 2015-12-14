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

   struct play_info{
        char name[25];
        long int bal;
        int bN;
    };
class blackJack {
public:
    blackJack();
    blackJack(int n);
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
    blackJack(const blackJack& orig);
    virtual ~blackJack();
    fstream player_info;
    play_info temp;
    void getInfo(player &);
    void writeInfo();

private:
    dealer dealer;
    vector<player> x;
    Deck deck;
    int numP;
    int cot;
};



    

#endif	/* GAME_H */

