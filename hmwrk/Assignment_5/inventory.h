#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#ifndef INVENTORY_H
#define	INVENTORY_H

class inventory {
public:
    inventory(int i = 0, int q = 0, float c = 0, float t = 0){
        itemN = i; cost = c; quan = q; tCost = t;
    }
    inventory(int i, float c, int q){
        itemN = i; cost = c; quan = q;
        setTotalCost();
    }
    void setItemNumber(int item){itemN = item;}
    void setQuantity (int quant){quan = quant;}
    void setCost(float cst){cost = cst;}
    void setTotalCost(){tCost = quan * cost;}
    int getItemNumber(){return itemN;}
    int getQuantity(){return quan;}
    float getCost(){return cost;}
    float getTotalCost(){return tCost;}
    virtual ~inventory();
private:
    int itemN, quan;
    float cost, tCost;

};

#endif	/* INVENTORY_H */

