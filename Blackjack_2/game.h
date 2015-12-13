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


class dealer {
public:
    dealer(){
        total = 0;
        status = "";
        ace = false;
    }
    void setTotal(int x){total +=x;}
    int giveTotal(){return total;}
    void setStatus(string s){status = s;}
    string giveStatus(){return status;}
    void setAce(bool b){ace = b;}
    bool giveAce(){return ace;}
private:
    int total;
    string status;
    bool ace;
};

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
    void checkWinner();
    void calcBal();
    void showResults();
    void dealOne(int);
    void setDeal(int t);
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

