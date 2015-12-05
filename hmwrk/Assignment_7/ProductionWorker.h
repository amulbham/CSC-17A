/* 
 * File:   ProductionWorker.h
 * Author: Amul.bham
 *
 * Created on December 4, 2015, 7:02 PM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H
#include "Employee.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class ProductionWorker:public Employee {
public:
    ProductionWorker(): Employee(){
        shift = 0;
        pay = 0;
    }
    ProductionWorker(string n, int nm, string d,int s,float p): Employee(n,nm,d){
        shift = s;
        pay = p;
    }
    void setShift(int s){shift = s;}
    void setPay(float p){pay = p;}
    void giveShift(){
        string day = "Day";
        string night = "Night";
        string error = "No Shift information on record";
        if (shift == 1){cout<<day<<endl;}
        else if (shift == 2){cout<<night<<endl;}
        else {cout<<error<<endl;}
    }
    void givePay(){
        cout<<"$ "<<pay<<endl;
    }
    ProductionWorker(const ProductionWorker& orig);
    virtual ~ProductionWorker();
private:
    int shift;
    float pay;

};

#endif	/* PRODUCTIONWORKER_H */

