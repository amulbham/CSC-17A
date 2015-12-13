/* 
 * File:   player.h
 * Author: Amul.bham
 *
 * Created on December 8, 2015, 9:12 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include "dealer.h"
using namespace std;

class player : public dealer {
public:
    player():dealer(){
        name = "";
        bal = 0;
        begBal = 0;
        bet = 0;
        binN = 0;
        newP = true;
    }
    string getName(){return name;}
    void setName(string n){name = n;}
    void setBal(long int b){bal = b;}
    void setBin(int n){binN = n;}
    void setBet(int c){bet = c;}
    void setbb(int x){begBal -=x; }
    void setStat();
    void setStat(int num){status = num;} 
    void setNew(int num){if (num == 0) newP = true; else newP = false;}
    void tie(){bal = bal;}
    void win(){bal +=bet;}
    void loss(){bal -=bet;}
    long int giveBal(){return bal;}
    int givePos(){return binN;}
    player(const player& orig);
    virtual ~player();
 
private:
    string name;
    long int bal,begBal;
    int bet;
    int binN;
    bool newP;
   

};

#endif	/* PLAYER_H */

