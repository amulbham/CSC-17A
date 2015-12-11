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
using namespace std;

class player {
public:
    player();
    string getName(){return name;}
    void setName(string n){name = n;}
    void setCardT(int card);
    int giveCardT(){return cardTot;}
    void setBal(int b){bal += b;}
    void setBin(int n){binN = n;}
    void setBet(int c){bet = c;}
    void setBegBal();
    void setbb(int x){begBal -=x; }
    void setAce(){ace = true;}
    void setStat(string s){status = s;}
    string giveStat(){return status;}
    void setNew(){retNew = "new";}
    void tie(){bal = bal;}
    void win(){bal +=bet;}
    void loss(){bal -=bet;}
    long int getBal(){return bal;}
    int returnB(){return binN;}
    player(const player& orig);
    virtual ~player();
 
private:
    string name,status,retNew;
    long int bal;
    int cardTot;
    int bet;
    long int begBal;
    int binN;
    bool ace;
   
   

};

#endif	/* PLAYER_H */

