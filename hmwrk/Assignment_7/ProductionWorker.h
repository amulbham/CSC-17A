/* 
 * File:   ProductionWorker.h
 * Author: rcc
 *
 * Created on December 2, 2015, 12:11 PM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H
#include "Employee.h"

class ProductionWorker: public Employee {
public:
    ProductionWorker():Employee(){
        shift = 0;
        pay = 0;
    };
    setShift(int s){shift = s;}
    setPay(float )
    ProductionWorker(const ProductionWorker& orig);
    virtual ~ProductionWorker();
private:
    int shift;
    float pay;

};

#endif	/* PRODUCTIONWORKER_H */

