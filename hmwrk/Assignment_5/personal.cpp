/* 
 * File:   personal.h
 * Author: Amul Bham
 * Purpose: Create a class that stores personal information
 * Created on November 17, 2015, 2:16 PM
 */
#include <iostream>
using namespace std;
#include "personal.h"

personal::personal() {
}

void personal::setName(string n){
    name = n;
}

void personal::setAdd(string add){
    address = add;
}

void personal::setPhone(string p){
    phone = p; 

}

void personal::setAge(int a){
    age = a;
}


personal::~personal() {
}

