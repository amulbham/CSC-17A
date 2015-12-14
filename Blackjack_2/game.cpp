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
#include "dealer.h"

using namespace std; 

blackJack::blackJack(int n) {
     numP = n;
     x.clear();
     while(x.size()<numP ){
         x.push_back(player());
     }
     for(int i =0; i<x.size();i++){
         getInfo(x[i]);
     }
    
}

void blackJack::setBets(){
    long int b;
    for(int i =0; i<x.size();i++){
        cout<<x[i].name<<": "<<endl;
        bet:
        cout<<"Please enter a bet for the current hand ($50.00 min): $"; cin>>b; 
        
        if(b<50 || b>x[i].giveBal()){
        cout<<"Invalid amount! Bet must be at least $50.00 and no greater than your total balance!"<<endl;
        cout<<"Your balance is : $"<<x[i].giveBal()<<endl;
        goto bet;
        }else{
        x[i].setBet(b);    
        cout<<"Thank you for your bet"<<endl;
        }
        disBord();
    }

}
void blackJack::dealCards(){
    deck.makeDeck();
    cout<<"Now Dealing first two cards for each player..."<<endl<<endl;
    int card=0;
    for(int i = 0; i<x.size();i++){
       cout<<x[i].name<<": "<<endl; 
       for(int j =0; j<2; j++) {
       card = deck.drawCard();
       x[i].setCardT(card);
       }
       cout<<"Total: "<<x[i].giveTotal()<<endl<<endl;
    }
    
    checkWinLoss();
    
    cout<<endl;
    disBord();
    cout<<"Proceeding to dealer hand...."<<endl;
     card = deck.drawCard();
     dealer.setCardT(card);
     cout<<"Dealer Total: "<<dealer.giveTotal()<<endl;
     if (dealer.giveTotal() > 21) dealer.setStat(3);
     else if (dealer.giveTotal() == 21 || dealer.giveTotal() >= 17) dealer.setStat(2);
     else dealer.setStat(1);
}
void blackJack::hitORstay(){
    for(int i = 0; i <x.size();i++){
       char d;
       int card;
       cout<<x[i].name<<endl;
       if (x[i].giveStat() == 1){
         do{
             cin.ignore();
            cout<<"Card Total: "<<x[i].giveTotal()<<endl;
            cout<<"Would you like to "
            "hit or stay? H/S"<<endl;
            cin.get(d); 
            if (tolower(d) == 'h'){
           card = deck.drawCard();
           x[i].setCardT(card);
            }else x[i].setStat(2);
       }while(x[i].giveStat() == 1); 
       }
       if (x[i].giveTotal() == 21){
           cout<<"BlackJack!"<<endl;
       }else if (x[i].giveTotal() > 21){
           cout<<"You Busted!"<<endl;
       }
        cout<<"Final Card Total: "<<x[i].giveTotal()<<endl<<endl;
        disBord();
    }
    checkWinLoss();
    cout<<endl;
    
}
void blackJack::dealerHand(){
    int card;
    cout<<"Current Total: "<<dealer.giveTotal()<<endl;
    cout<<"Now finishing the dealer hand..."<<endl<<endl;
    if (dealer.giveStat() == 1){
        do{
        card = deck.drawCard();
        dealer.setCardT(card);
        }while(dealer.giveTotal()<17);
    }
        cout<<"New Total: "<<dealer.giveTotal()<<endl;
    
    if (dealer.giveTotal() > 21){
        dealer.setStat(3);
        cout<<"Dealer has Busted!"<<endl;
    }else if (dealer.giveTotal() == 21){
        dealer.setStat(2);
        cout<<"Dealer has a BlackJack!"<<endl<<endl;
    }else dealer.setStat(2);
}
void blackJack::checkWinLoss(){
    disBord();
    cout<<endl<<"Results: "<<endl;
    for (int i = 0; i<x.size();i++){
        cout<<x[i].name<<":"<<endl;
        if (x[i].giveTotal()== 21){
            cout<<"you hit a blackjack, congratulations!"<<endl;
            x[i].setStat(2);        
        }else if (x[i].giveTotal() > 21){
            x[i].setStat(3);
            cout<<"you busted! Sorry!"<<endl;
            cout<<"Card Total: "<<x[i].giveTotal()<<endl<<endl;
        }else {
            x[i].setStat(1);
            cout<<"Card Total: "<<x[i].giveTotal()<<endl;
    }
        cout<<endl;
}
}
void blackJack::checkWinner(){
    for(int i = 0; i< x.size(); i++){
      if (x[i].giveTotal() >21) x[i].setStat(3);
      if(x[i].giveStat() != 3){
        if (dealer.giveTotal() == 21){
            if (x[i].giveTotal() != 21 ){
                x[i].setStat(3);
            }else x[i].setStat(4);
       }else if (dealer.giveTotal() < 21 ){
            if (x[i].giveTotal()> dealer.giveTotal()){
                x[i].setStat(5);
            }else if(x[i].giveTotal() == dealer.giveTotal()){x[i].setStat(4);}
            else x[i].setStat(3);
       }else if (dealer.giveTotal()> 21) x[i].setStat(5);
   } 
    }
}

void blackJack::showResults(){
    for (int i = 0; i<x.size(); i++){
        if (x[i].giveStat() == 5){
            x[i].win();
        cout<<x[i].name<<" you have won!"<<endl;
        cout<<"Balance: "<<x[i].giveBal()<<endl;
        }else if (x[i].giveStat() == 3){
            x[i].loss();    
        cout<<x[i].name<<" you have lost!"<<endl;
        cout<<"Balance: "<<x[i].giveBal()<<endl;
        }else{
        cout<<x[i].name<<" you have tied the dealer!"<<endl;
        cout<<"Balance: "<<x[i].giveBal()<<endl;
        }
        disBord();
    }
}

void blackJack::newHand(){
    long int y;
    dealer.reset();
    for (int i = 0; i< x.size(); i++){
        x[i].reset();
        if (x[i].giveBal() < 0){
           do{ 
            cout<<x[i].name<<endl;
            cout<<"You must purchase more chips to continue as you are below 00.00!"<<endl;
            cout<<"Amount(100.00 min::10,000 max): "; cin>>y;
           }while(y < 100 || y> 10000 );
           x[i].setBal(y);
        }
    }
    
}

void blackJack::disBord(){
cout<<"****************************************************************"<<endl;
}

blackJack::blackJack(const blackJack& orig) {
}

void blackJack::getInfo(player &curr){
    bool t = true;
    char c;
    //Determine if the user is returning or if it is their first time 
    _rORn:
    cout<<"Player "<<cot+1<<":"<<endl;
    cout<<"Are you returning or a new player? (r/n)"<<endl;
    cin>>c; cin.ignore(); 
    if (tolower(c) != 'r' && tolower(c) != 'n') {
        cout<<"Invalid option!"<<endl; goto _rORn;
    } 
    cot++;
    int count = 1;
    /*if continuing, read all the players currently in the file and ask
     the user to select which account they would like to play on */
    if (tolower(c) == 'r'){
        player_info.open("player.txt", ios::in | ios::binary);
        if (!player_info) {cout<<"Error opening file!"<<endl;}
        //Open the player file for binary input 
        cout<<"The current players on record are ..."<<endl;
        disBord();
        //Static cast the binary data to character and display
        
        player_info.read(reinterpret_cast<char *>(&temp), sizeof(temp));
        
       /*Read out all the players, incremented by byte size, each player
        being stored as an object, until the end of the file is reached*/
        while(!player_info.eof()){
            cout<<"Player "<<count<<endl;
            cout<<"Name: "<<temp.name<<endl;
            cout<<"Balance: $"<<temp.bal<<endl;
            player_info.read(reinterpret_cast<char *>(&temp), sizeof(temp));
            count++;
            disBord();
        }
        //Close the file to prevent memory leaks 
         player_info.close(); int ply;
         //Allow the user to choose an account to play on 
         do{
         cout<<"Enter the player number of the account you would"
                " like to play on: ";
         cin>>ply; ply -=1;
         for(int i =0; i<x.size();i++){
             if(ply == x[i].givePos()){
                 t = false;
                 cout<<"This account is already in use!"<<endl;
                 break;
             }else {t = true;}
         }
         
         }while(!t);
         
         //Read in the player information based on the account choosen 
         player_info.open("player.txt", ios::in|ios::out|ios::binary);
         //Seek to the memory location of the user account, based on the num
         player_info.seekg(sizeof(temp)*(ply), ios::beg);
         //Read in the player information, including their name and balance 
         player_info.read(reinterpret_cast<char *>(&temp),sizeof(temp));
         strcpy(curr.name, temp.name); curr.setBal(temp.bal);
         curr.setBin(ply); curr.setNew(1);
         cout<<"Welcome Back "<<curr.name<<"!"<<endl;
         //Determine if the user would like to purchase more coins 
         cout<<"Your current balance is $"<<curr.giveBal()<<endl;
         cout<<"would you like to buy in more? (Y/N)"<<endl; 
         cin.ignore(); cin.get(c);
         if (tolower(c) == 'y'){
             cout<<"Enter how much more you like to buy in($10,000.00 Limit) or type 0 for none"<<endl;
         //Get the buy in as a cstring to prevent run time errors, convert to int using atoi.     
            cin.ignore(); long int c; cin>>c; c += curr.giveBal();
         curr.setBal(c);} //Add the buy in to the total player balance 
         
         cout<<"Your current balance is $"<<curr.giveBal()<<endl;
         player_info.close();
                 
    /*if the user is new, call the greeting function and input the name
     to the file*/  
         
    }else{
    curr.setNew(0);  curr.setBin(30);
    char r;
    cout<<"A new player! Terrific! First I'll need your name: "<<endl;
    cin.getline(curr.name,25); 
    cout<<"Would you like to hear the rules? (Y/N)"<<endl;
    cin.get(r);cin.ignore();
    if(tolower(r)== 'y'){
        disRules();
    }
    disBord();
    //Determine how much the player wants to buy into game
    _buyin:
    cout<<"How much would you like to buy in?($100.00 minimum::$10,000.00 limit)"<<endl;
    long int b;
    cin>>b; if (b<100 || b>10000) {cout<<"Invalid amount!"<<endl;goto _buyin;}
    curr.setBal(b); 
    }
    disBord();
}
void blackJack::writeInfo(){
 for(int i =0; i<x.size(); i++){
     strcpy(temp.name, x[i].name);
     temp.bal = x[i].giveBal();
     temp.bN = x[i].givePos();
     player_info.open("player.txt", ios::in | ios::out | ios::binary);
     if(x[i].giveNew()== true) {
        player_info.close();
        player_info.open("player.txt",ios::binary| ios::app);
        player_info.write(reinterpret_cast<char *>(&temp),sizeof(temp));
     }else{
        player_info.seekp((x[i].givePos()) * sizeof(temp), ios::beg);
        player_info.write(reinterpret_cast<char *>(&temp),sizeof(temp));
     }
 }
      player_info.close();
}
blackJack::~blackJack() {
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
        disBord();
        cout<<"Also, Jack, Queens, King all have a value of 10\n"
                "while the Ace has a value of either 1 or 11\n"
                "All other cards represent their face value\n";
        cout<<"You will buy in an amount of your choosing which will be tracked throughout the game"<<endl;
        cout<<"At the start of each hand, you will place a bet: "<<endl;
        cout<<"If you win, you win 2x your original bet"<<endl;
        cout<<"A loss means you lose the amount of the bet"<<endl;
        cout<<"And finally a draw or PUSH results in no loss of money"<<endl;
        cout<<"Minimum bets: $ 50.00   "<<"Maximum bets: $ ACC BAL  "<<endl<<endl;
        disBord();
        cout<<"Also note, you are playing against the dealer, so the card values"
                "\nof other players do not affect if you win or lose, you are"
                "\nonly competing against the dealer!"<<endl;

}



