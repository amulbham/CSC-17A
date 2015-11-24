/* 
 * File:   Numbers.h
 * Author: Amul.bham
 *
 * Created on November 23, 2015, 6:57 PM
 */

#ifndef NUMBERS_H
#define	NUMBERS_H
#include <iostream>
using namespace std;
class Numbers {
public:
    Numbers(int);
    void print(int);
    Numbers(const Numbers& orig);
    virtual ~Numbers();
private:
    int value;
    
};

#endif	/* NUMBERS_H */

