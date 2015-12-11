/* 
 * File:   game.cpp
 * Author: Amul.bham
 * 
 * Created on December 9, 2015, 12:14 AM
 */


#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include "game.h"
#include "Deck.h"
#include "player.h"
using namespace std; 

blackJack::blackJack(int n) {
     numP = n;
     while(x.size()<numP ){
         x.push_back(player());
     }
     Deck deck;
     for(int i =0; i<x.size();i++){
         getInfo(x[i]);
     }
    
}
void blackJack::disBord(){
cout<<"****************************************************************"<<endl;
}

blackJack::blackJack(const blackJack& orig) {
}
void blackJack::getInfo(player &curr){
    fstream player_info;
    bool t = true;
    char c;
    player output;
    //Determine if the user is returning or if it is their first time 
    _rORn:
    cout<<"Player "<<cot+1<<":"<<endl;cot++;
    cout<<"Are you returning or a new player? (r/n)"<<endl;
     cin.get(c);cin.ignore(); 
    if (tolower(c) !== 'r' || tolower(c) !== 'n') {
        cout<<"Invalid option!"<<endl; goto _rORn;
    } 
    int count = 1;
    /*if continuing, read all the players currently in the file and ask
     the user to select which account they would like to play on */
    if (tolower(c) == 'r'){
        player_info.open("player.txt", ios::in | ios::binary);
        //Open the player file for binary input 
        cout<<"The current players on record are ..."<<endl;
        //Static cast the binary data to character and display
        
        player_info.read(reinterpret_cast<char *>(&output), sizeof(output));
        
       /*Read out all the players, incremented by byte size, each player
        being stored as an object, until the end of the file is reached*/
        while(!player_info.eof()){
            cout<<"Player "<<count<<endl;
            cout<<"Name: "<<output.getName()<<endl;
            cout<<"Balance: $"<<output.getBal()<<endl;
            player_info.read(reinterpret_cast<char *>(&output), sizeof(output));
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
         
         //Read in the player information based on the account choosen 
         player_info.open("player.txt", ios::in|ios::out|ios::binary);
         //Seek to the memory location of the user account, based on the num
         player_info.seekg(sizeof(curr)*(count-1), ios::beg);
         //Read in the player information, including their name and balance 
         player_info.read(reinterpret_cast<char *>(&curr),sizeof(curr));
         curr.setBin(count - 1);
         cout<<"Welcome Back "<<curr.getName()<<"!"<<endl;
         //Determine if the user would like to purchase more coins 
         cout<<"Your current balance is $"<<curr.getBal()<<endl;
         cout<<"would you like to buy in more? (Y/N)"<<endl; 
         cin.get(c);cin.ignore();
         if (tolower(c) == 'y'){
             cout<<"Enter how much more you like to buy in($10,000.00 Limit) or type 0 for none"<<endl;
         //Get the buy in as a cstring to prevent run time errors, convert to int using atoi.     
         char y[6];cin.ignore();  cin.getline(y,6);
         curr.setBal(atoi(y));} //Add the buy in to the total player balance 
         
         cout<<"Your current balance is $"<<curr.getBal()<<endl;
         player_info.close();
         curr.setBegBal();
                 
    /*if the user is new, call the greeting function and input the name
     to the file*/     
    }else{
    curr.setNew();  
    string n; char r;
    cout<<"A new player! Terrific! First I'll need your name: "<<endl;
    getline(cin,n); curr.setName(n);
    cout<<"Would you like to hear the rules? (Y/N)"<<endl;
    cin.get(r);cin.ignore();
    if(tolower(r)== 'y'){
        disRules();
    }
    disBord();
    //Determine how much the player wants to buy into game
    _buyin:
    cout<<"How much would you like to buy in?($500.00 minimum::$10,000.00 limit)"<<endl;
    int b;
    cin>>b; if (b<500 || b>10000) {cout<<"Invalid amount!"<<endl;goto _buyin;}
    curr.setBal(b); curr.setBegBal();
    }
}

void blackJack::disRules(){
    cout<<"Basically the point of the game is to get to 21 or as close as"
                "possible without going over,\notherwise you lose"
                "\n,in addition, if my card total is higher than yours"
                " you also lose"<<endl;
    disBord();
        cout<<"I will deal 2 cards from a regular deck of cards \n"
                "depending on the total value of these cards, you must\n"
                "decide if you want another card or stay where you are (hit) \n"
                "Also, note that my job as a dealer is to always hit if my card\n"
                "value is below 17,if i bust (go over 21) then you automatically\n"
                "win. So its your choice whether you want to pursue a higher card "
                "value(at the risk of busting)\nor stay and wait for the dealer to bust\n"
                "If we score a tie, then the hand ends in a draw \n";
        cout<<"Also, Jack, Queens, King all have a value of 10\n"
                "while the Ace has a value of either 1 or 11\n"
                "All other cards represent their face value\n";
        cout<<"You will buy in an amount of your choosing which will be tracked throughout the game"<<endl;
        cout<<"At the start of each hand, you will place a bet: "<<endl;
        cout<<"If you win, you win 2x your original bet"<<endl;
        cout<<"A loss means you lose the amount of the bet"<<endl;
        cout<<"And finally a draw or PUSH results in no loss of money"<<endl;
        cout<<"Minimum bets: $ 100.00   "<<"Maximum bets: $ 1000.00  "<<endl<<endl;
        cout<<"Also note, you are playing against the dealer, so the card values"
                "\nof other players do not affect if you win or lose, you are"
                "\nonly competing against the dealer!"<<endl;

}
blackJack::~blackJack() {
}

