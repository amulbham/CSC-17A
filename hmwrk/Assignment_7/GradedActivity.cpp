/* 
 * File:   GradedActivity.cpp
 * Author: Amul.bham
 * 
 * Created on December 4, 2015, 11:51 PM
 */

#include "GradedActivity.h"

char GradedActivity::getLetterGrade() const
 {
 char letterGrade; // To hold the letter grade

 if (score > 89)
 letterGrade = 'A';
 else if (score > 79)
 letterGrade = 'B';
 else if (score > 69)
 letterGrade = 'C';
 else if (score > 59)
 letterGrade = 'D';
 else
 letterGrade = 'F';

 return letterGrade;
 }
