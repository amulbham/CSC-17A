/* 
 * File:   Essay.h
 * Author: Amul.bham
 *
 * Created on December 4, 2015, 11:48 PM
 */

#ifndef ESSAY_H
#define	ESSAY_H
#include <iostream>
#include "GradedActivity.h"
using namespace std;

class Essay: public GradedActivity {
public:
    Essay():GradedActivity(){};
    Essay(int x,int y,int z,int m){
        score = x + y + z + m;
    }
    Essay(const Essay& orig);
    virtual ~Essay();
private:

};

#endif	/* ESSAY_H */

