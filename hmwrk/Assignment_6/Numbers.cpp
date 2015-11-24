/* 
 * File:   Numbers.cpp
 * Author: Amul.bham
 * 
 * Created on November 23, 2015, 6:57 PM
 */
#include <iostream>
#include "Numbers.h"
using namespace std;


Numbers::Numbers(int num) {
    value = num;
    print(value);
}

void Numbers::print(int digits){
       int ones,tens,hundreds, thousands;  
       thousands=(digits/1000)%10;
       hundreds=((digits/100)%100)%10;
       tens=(digits/10)%10;
       ones=digits%10;
       
       switch(thousands){
                         case 1:
                              cout<<"One Thousand "<<tens;
                              break;
                         case 2:
                              cout<<"Two Thousand ";
                              break;
                         case 3:
                              cout<<"Three Thousand ";
                              break;
                         case 4:
                              cout<<"Four Thousand ";
                              break;
                         case 5:
                              cout<<"Five Thousand ";
                              break;
                         case 6:
                              cout<<"Six Thousand ";
                              break;
                         case 7:
                              cout<<"Seven Thousand ";
                              break;
                         case 8:
                              cout<<"Eight Thousand ";
                              break;
                         case 9:
                              cout<<"Nine Thousand ";
                              break;
                         default:
                              break;
                         }
       switch (hundreds){
                         case 1:
                              cout<<"One Hundred ";
                              break;
                         case 2:
                              cout<<"Two Hundred ";
                              break;
                         case 3:
                              cout<<"Three Hundred ";
                              break;
                         case 4:
                              cout<<"Four Hundred ";
                              break;
                         case 5:
                              cout<<"Five Hundred ";
                              break;
                         case 6:
                              cout<<"Six Hundred ";
                              break;
                         case 7:
                              cout<<"Seven Hundred ";
                              break;
                         case 8:
                              cout<<"Eight Hundred ";
                              break;
                         case 9:
                              cout<<"Nine Hundred ";
                              break;
                         }
                         
       if (tens == 1){
                 
                 switch (ones){
                        case 1:
                             cout<<"Eleven ";
                             break;
                        case 2:
                             cout<<"Twelve ";
                             break;
                        case 3:
                             cout<<"Thirteen ";
                             break;
                        case 4:
                             cout<<"Fourteen ";
                             break;
                        case 5:
                             cout<<"Fifteen ";
                             break;
                        case 6:
                             cout<<"Sixteen ";
                             break;
                        case 7:
                             cout<<"Seventeen ";
                             break;
                        case 8:
                             cout<<"Eighteen ";
                             break;
                        case 9:
                             cout<<"Nineteen ";
                             break;
                        }
       }
       
       else {
            
            switch (tens){
                         case 1:
                              cout<<"Ten ";
                              break;
                         case 2:
                              cout<<"Twenty ";
                              break;
                         case 3:
                              cout<<"Thirty ";
                              break;
                         case 4:
                              cout<<"Fourty ";
                              break;
                         case 5:
                              cout<<"Fifty ";
                              break;
                         case 6:
                              cout<<"Sixty ";
                              break;
                         case 7:
                              cout<<"Seventy ";
                              break;
                         case 8:
                              cout<<"Eighty ";
                              break;
                         case 9:
                              cout<<"Ninety ";
                              break;
                         }
                   
            switch (ones){
                         case 1:
                              cout<<"One ";
                              break;
                         case 2:
                              cout<<"Two ";
                              break;
                         case 3:
                              cout<<"Three ";
                              break;
                         case 4:
                              cout<<"Four ";
                              break;
                         case 5:
                              cout<<"Five ";
                              break;
                         case 6:
                              cout<<"Six ";
                              break;
                         case 7:
                              cout<<"Seven ";
                              break;
                         case 8:
                              cout<<"Eight ";
                              break;
                         case 9:
                              cout<<"Nine ";
                              break;
                         }
            }
                         
       
       
       
       cout<<endl<<endl;
                       
       }
                              
       
       


Numbers::Numbers(const Numbers& orig) {
}

Numbers::~Numbers() {
}

