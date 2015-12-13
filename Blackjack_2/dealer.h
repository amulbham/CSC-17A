/* 
 * File:   dealer.h
 * Author: Amul.bham
 *
 * Created on December 12, 2015, 7:51 PM
 */
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

#ifndef DEALER_H
#define	DEALER_H

class dealer {
public:
    dealer();
    void setAce(int num){
        if (num == 0) ace = false;
        else ace = true;
    }
    virtual void setStat();
    void setDone(); 
    void setCardT(int card);
    void addTotal(int card);
    virtual void setStat(int num){status = num;} 
    bool giveAce() {return ace;}
    int giveTotal(){return cardTot;}
    int giveStat(){return status;}
    dealer(const dealer& orig);
    virtual ~dealer();
protected:
    int cardTot;
    /*HAND KEY:
     status = 1 => player is under 21 and has the option of continuing to hit
     * , if they are finished their status will change to 2
     status = 2 => player is finished with the hand or hit a 21 
     status = 3 - player has lost the hand and has no chance of winning*/
    int status;
    bool ace;

};

#endif	/* DEALER_H */

