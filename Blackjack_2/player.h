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
using namespace std;

class player {
public:
    player();
    string getName(){return name;}
    int getBal(){return bal;}
    void setBal(int b){bal += b;}
    void setB(int n){binN = n;}
    int returnB(){return binN;}
    player(const player& orig);
    virtual ~player();
 
private:
    string name;
    int bal;
    int cardTot;
    int bet;
    int begBal;
    int binN;
    bool ace;
    bool status;

};

#endif	/* PLAYER_H */

