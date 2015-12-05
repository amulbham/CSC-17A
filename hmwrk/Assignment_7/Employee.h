/* 
 * File:   Employee.h
 * Author: Amul.bham
 *
 * Created on December 4, 2015, 6:50 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;



class Employee {
public:
    Employee(string n, int nm, string d){
        name = n;
        num = nm;
        hire = d;
   }
    Employee(){
        name = "";
        num = 0;
        hire = "";
    }
    void setName(string n){name = n;}
    void setNum(int nm){num = nm;}
    void setHire(string d){
            hire=d;
    }
    void giveName(){cout<<name<<endl;}
    void giveNum(){cout<<num<<endl;;}
    void giveDate(){cout<<hire<<endl;;}
    Employee(const Employee& orig);
    virtual ~Employee();
private:
    string name;
    int num;
    string hire;
};

#endif	/* EMPLOYEE_H */

