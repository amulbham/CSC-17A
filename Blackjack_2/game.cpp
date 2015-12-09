/* 
 * File:   game.cpp
 * Author: Amul.bham
 * 
 * Created on December 9, 2015, 12:14 AM
 */

#include "game.h"
#include "Deck.h"
#include "player.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
using namespace std; 

game::game(int n) {
     numP = n;
     while(x.size()<numP ){
         x.push_back(player());
     }
     Deck deck;
     for(int i =0; i<x.size();i++){
         getInfo(x[i]);
     }
    
}
void game::disBord(){
cout<<"****************************************************************"<<endl;
}

game::game(const game& orig) {
}
void game::getInfo(player &curr){
    fstream player_info;
    char c;
    bool t = true;
    
    //Determine if the user is returning or if it is their first time 
    cout<<"Player "<<cot+1<<":"<<endl;cot++;
    cout<<"Are you returning or a new player? (r/n)"<<endl;
    cin.ignore(); cin.get(c);   
    int count = 1;
    /*if continuing, read all the players currently in the file and ask
     the user to select which account they would like to play on */
    if (tolower(c) == 'r'){
        player_info.open("player.txt", ios::in | ios::binary);
        //Open the player file for binary input 
        cout<<"The current players on record are ..."<<endl;
        //Static cast the binary data to character and display
        
        player_info.read(reinterpret_cast<char *>(&curr), sizeof(curr));
        
       /*Read out all the players, incremented by byte size, each player
        being stored as an object, until the end of the file is reached*/
        while(!player_info.eof()){
            cout<<"Player "<<count<<endl;
            cout<<"Name: "<<curr.getName()<<endl;
            cout<<"Balance: $"<<curr.getBal()<<endl;
            player_info.read(reinterpret_cast<char *>(&curr), sizeof(curr));
            count++;
        }
        //Close the file to prevent memory leaks 
         player_info.close();
         //Allow the user to choose an account to play on 
         do{
         cout<<"Enter the player number of the account you would"
                "like to play on"<<endl;
         cin>>count;
         for(int i =0; i<x.size();i++){
             if(count - 1 == x[i].returnB()){
                 t = false;
                 cout<<"This account is already in use!"<<endl;
                 break;
             }else {t = true;}
         }
         
         }while(!t);
         
         curr.setB(count - 1);
         //Read in the player information based on the account choosen 
         player_info.open("player.txt", ios::in|ios::out|ios::binary);
         //Seek to the memory location of the user account, based on the num
         player_info.seekg(sizeof(curr)*(count-1), ios::beg);
         //Read in the player information, including their name and balance 
         player_info.read(reinterpret_cast<char *>(&curr),sizeof(curr));
         cout<<"Welcome Back "<<curr.getName()<<"!"<<endl;
         //Determine if the user would like to purchase more coins 
         cout<<"Your current balance is $"<<curr.getBal()<<", would"
                 " you like to buy in more? y/n"<<endl;
         cin>>c;
         if (tolower(c) == 'y'){
             cout<<"Enter how much more you like to buy in or type 0 for none "<<curr.getName()<<endl;
         //Get the buy in as a cstring to prevent run time errors, convert to int using atoi.     
         char y[6];cin.ignore();  cin.getline(y,6);
         curr.setBal(atoi(y));} //Add the buy in to the total player balance 
         cout<<"Your current balance is $"<<curr.getBal()<<endl;
                  player_info.close();
                  
    /*if the user is new, call the greeting function and input the name
     to the file*/     
    }else{
    //Begin greeting, get user name 
    disBord();
    //Determine how much the player wants to buy into game
    cout<<"How much would you like to buy in "<<curr.getName()<<" ?"<<endl;
    int b;
    cin>>b; curr.setBal(b);
    }
}
game::~game() {
}

