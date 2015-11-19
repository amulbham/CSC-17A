/* 
 * File:   personal.h
 * Author: Amul Bham
 * Purpose: Create a class that stores personal information
 * Created on November 17, 2015, 2:16 PM
 */
#include <iostream>
#include <vector>
using namespace std;
#ifndef PERSONAL_H
#define	PERSONAL_H


class personal {
public:
    personal();
    void setName(string n);
    void setAdd(string add);
    void setAge(int a);
    void setPhone(string p);
    void getName(){cout<<name<<endl;}
    void getAdd(){cout<<address<<endl;}
    void getAge(){cout<<age<<endl;}
    void getPhone(){cout<<phone<<endl;}
    virtual ~personal();
private:
    string name, address,phone;
    int age;
};

#endif	/* PERSONAL_H */

