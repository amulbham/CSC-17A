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
    player(const player& orig);
    virtual ~player();
private:
    struct info{
        string name;
        string login;
        int bal;
    };
    int cardTot;
    int bet;
    int begBal;
    int binN;
    bool ace;
    bool status = false;

};

#endif	/* PLAYER_H */

