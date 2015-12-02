/* 
 * File:   Employee.h
 * Author: Amul Bham
 *
 * Created on December 2, 2015, 11:53 AM
 */
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#ifndef EMPLOYEE_H
#define	EMPLOYEE_H



class Employee {
public:
    Employee();
    Employee(int n,char m, char d){
        num = n;
        for(int i = 0; i<25; i++){
            name[i] = m + i;
        }
        for (int i =0; i<8; i++){
            date[i] = d + i;
        }
    }
    setName(char m){
     for(int i = 0; i<25; i++){
            name[i] = m + i;
        }
    };
    setNum(int n){num = n;}
    setDate(char d){
    for (int i =0; i<8; i++){
            date[i] = d + i;
        }
    }
    GiveName(){return name;}
    GiveDate(){return date;}
    GiveNum(){return num;}
    Employee(const Employee& orig);
    virtual ~Employee();
private:
    char name[25];
    int num;
    char date[8];
};
#endif	/* EMPLOYEE_H */

