/* 
 * File:   retailitem.h
 * Author: Amul Bham
 * Purpose: Problem number 5 - Retail Item class 
 * Created on November 17, 2015, 2:16 PM
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#ifndef RETAILITEM_H
#define	RETAILITEM_H

class RetailItem {
public:
    RetailItem(string x ="x", int y =0, float z = 0){
        desc = x; units = y; price = z;
    }
    string getDesc(){
        return desc;
    }
    int getUnits(){
        return units;
    }
    float getPrice(){
        return price;
    }
    virtual ~RetailItem();
private:
    string desc;
    int units;
    float price;
};

#endif	/* RETAILITEM_H */

