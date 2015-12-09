/* 
 * File:   main.cpp
 * Author: Amul Bham (Project 1)
 * Purpose: To play Blackjack against 
 * A.I. implementing methods learned from
 * chapters 9-12.
 * Created on October 17, 2015, 2:42 PM
 */
//System Libraries
#include <iostream>     
#include <algorithm>    
#include <ctime>        
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

struct Curhand{
    int cards;  //the players cards for the current hand 
    int cardTot;//the player cart total for the current hand
    int bet;    //the player bet for the current hand 
};

//Global Constants

//User Libraries
#include "Deck.h"
#include "player.h"

//Function Prototypes
void displayGreeting(); //function for greeting player
void getUser(vector<player>,int); //determines user, initiates greeting
void hitORstay(Curhand &,Deck &);//handles logic for hitting/staying

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
     int p;
     vector<player> x;

     
    cout<<"                 Casino Bham's BlackJack"<<endl;
    cout<<"****************************************************************"<<endl;
   
     //Determine how many players are going to play
    _np:
     cout<<"How many players would like to play? (Up to 4 total)"<<endl;
     cin>>p;
     
     if (p<1 || p>4) {cout<<"Invalid players!"<<endl; goto _np;}
     
     int i =0;
     while(x.size()<p ){
         x.push_back(player());
         getUser(x,i);
         i++;
     }
     
  
     
     
     
     
     int begBal = x.balance; //tracks what the user started out with
     fstream player_info("player.txt", ios::in | ios::out | ios::binary);
  //game loop begins here   
  do{
      //Values that must be reset at the start of each hand
      y = &x.balance; //Pointer to track winning/losses of money
      player.cardTot = 0;   //RESET dealer and player hands at the beginning of each hand
      dealer.cardTot = 0;
      //Only seek to the beginning of the record if the player is continuing, 
      //If the player is new, the record must be appended versus rewritten
      if(num!=0){
     player_info.seekg(sizeof(Play)*(num-1), ios::beg);
      }
    
    //Game begins here by asking how the user would like to bet on first hand
    cout<<"How much would you like to bet?"<<endl;
    cin>>player.bet;
    *y -=player.bet; //subtract bet from starting balance
    cout<<"Okay sounds good, your remaining balance is $"<<*y<<endl;
    cout<<"****************************************************************\n";
    //first two player cards are dealt
    cout<<"Your first two cards are.... "<<endl;  
    for(int i = 0;i<2;i++){
    player.cards = cards.deck[cards.count]; cards.count++; 
    valueCards (player);
    }  
    cout<<x.name<<" your hand equates to "<<player.cardTot<<endl<<endl; //first two card total
    cout<<"****************************************************************\n";
    
    bool win = false; /*value to guide program NOT to display 21 message again if 
                  user draws a 21 on first two cards*/
    if(player.cardTot==21){ 
        cout<<"Congratulations you got blackjack! ☜(˚▽˚)☞"<<endl;
        cout<<"****************************************************************\n";
        win = true; //prevents a repeat 
    }
    
    //Then the dealer draws their first card value
    cout<<"My first card is a.... "<<endl;
    dealer.cards = cards.deck[cards.count]; cards.count++; 
    valueCards(dealer);
    cout<<"My hand so far equates to "<<dealer.cardTot<<endl; //dealer first card total
    cout<<"****************************************************************\n";
    
    /*Player then must decide to hit or stay, loop continues until
     player busts, hits a 21, or decides to stay */    
    if (!win){ //only runs if player has not already hit a 21    
        hitORstay(player,cards);
    }
     
    /*At this point, the program determines if the user has busted or reached
    blackjack, if user busts, dealer hand is skipped as the user has lost,
    else the dealer hand continues until dealer hits 17 or goes over 21*/
     if(player.cardTot==21 && !win){
        cout<<"Congratulations you got blackjack! ☜(˚▽˚)☞"<<endl;
        cout<<"****************************************************************\n";
     }else if(player.cardTot>21){
        cout<<"Busted! You lose! ¯|_(ツ)_/¯ "<<endl;
    cout<<"****************************************************************\n";
   
    /*Dealer hand continues until dealer hits 17 or higher or goes over 21,
     only executes if player has not busted*/
    }if (player.cardTot <=21){
        cout<<"And now, the rest of my hand..."<<endl;
        do{ //Loop dealer hand till card total at 17 or higher
          dealer.cards = cards.deck[cards.count]; cards.count++;
          valueCards(dealer);
        }while(dealer.cardTot <17);
        
   cout<<"My Hand equates to "<<dealer.cardTot<<endl;  //dealer card value total
   cout<<"****************************************************************\n";
  
   /*Program then determines who had the higher card value total,
  if user wins, they win twice the amount they bet, if they lose user
  loses their bet, if a tie, bet is returned to the user*/
        if (dealer.cardTot<player.cardTot || dealer.cardTot>21){ //if user value is higher or dealer busts
            cout<<"Congratulations "<<x.name<<
                " you won the hand ☜(˚▽˚)☞ "<<endl;
            *y +=player.bet *2; //user wins 2 * the amount they bet
        }else if (dealer.cardTot>player.cardTot && dealer.cardTot<=21){ //if dealer value is higher
            cout<<"Thank you for playing "<<x.name<< ", but you lose (◑‿◐)"<<endl;
        }else if (dealer.cardTot == player.cardTot){ //if card values are equal
            cout<<"Draw!"<<" I guess that means you technically "
                    "aren't a loser..."<<x.name<<endl;
            *y +=player.bet; //if draw, user gets the bet back
        }
    }  
  /*Program then lets the user know of their remaining balance to inform them
    on their winnings/losings or if they are the same, and prompts the user
    if they would like to play a new hand*/
    cout<<"****************************************************************\n";
    cout<<"Your remaining balance is $"<<*y<<endl; 
    
    cout<<"****************************************************************\n";
    cout<<"Do you want to play another hand, or walk away now?"<<endl;
    cout<<"y/n \n";
    cin>>answ; 
    
    /*set dealer and player card totals back to 0 for new hand*/
    player.bet = 0;
   
 /*if user would like to play a new hand, program loops back to making a bet
  * ,asks the user for a new bet, and the rest of the program
    proceeds as normal, when card 40 (z=40) is reached, the deck shuffles*/
 }while(tolower(answ) == 'y');
 
 //Output the results of the game, if the user has lost or gained money
 if (x.balance>=begBal){
 cout<<"****************************************************************\n";
 cout<<"You winnings for the day are $"<<x.balance - begBal<<"\ngo buy yourself"
         " something nice "<<x.name<<endl; 
 }else {
 cout<<"Looks like you lost $"<<begBal - x.balance<<" today, better luck next time "<<x.name<<endl;
 } 
     
     //write the remaining balance to the balance folder
     //If the user is a new user, then append their information to the end of the file
     //to create a new account
     if (num == 0){
         player_info.close();
         fstream player_info("player.txt",ios::binary| ios::app);
         player_info.write(reinterpret_cast<char *>(&x),sizeof(x));
     }else{//If the user already has an account, rewrite their account with their 
         //New balance
        player_info.seekp((num-1) * sizeof(Play), ios::beg);
        player_info.write(reinterpret_cast<char *>(&x),sizeof(x));
     }
     //Close out the player info file to prevent memory leaks
     player_info.close();
    
    //Exit stage right    
    return 0;
}

/****************************************************************************
                          getUser    
 ***************************************************************************
 
 Purpose : To determine if the user is returning or is a completely new player,
 * if a new player, greeting function is called, else program reads name and
 * balance from txt file. Get the player name and balance.
 
 Input : name,balance
 Output: greeting function or a welcome back message
 
 Return --> void
 *******************************************************************************/

void getUser(vector<player> curr,int x){
    fstream player_info;
    char c;
    //Determine if the user is returning or if it is their first time 
    cout<<"Would you like to continue(c) or start a new game(n)? c/n"<<endl;
    cin.get(c);
    cin.ignore();
    int count = 1;
    
    /*if continuing, read all the players currently in the file and ask
     the user to select which account they would like to play on */
    if (tolower(c) == 'c'){
        player_info.open("player.txt", ios::in | ios::binary);
        //Open the player file for binary input 
        cout<<"The current players on record are ..."<<endl;
        //Static cast the binary data to character and display
        player_info.read(reinterpret_cast<char *>(&play), sizeof(play));
       /*Read out all the players, incremented by byte size, each player
        being stored as an object, until the end of the file is reached*/
        while(!player_info.eof()){
            cout<<"Player "<<count<<endl;
            cout<<"Name: "<<play.name<<endl;
            cout<<"Balance: $"<<play.balance<<endl<<endl;
            player_info.read(reinterpret_cast<char *>(&play), sizeof(play));
            count++;
        }
        //Close the file to prevent memory leaks 
         player_info.close();
         //Allow the user to choose an account to play on 
         cout<<"Enter the player number of the account you would\n"
                "like to play on"<<endl;
         cin>>num;
         //Read in the player information based on the account choosen 
         player_info.open("player.txt", ios::in|ios::out|ios::binary);
         //Seek to the memory location of the user account, based on the num
         player_info.seekg(sizeof(play)*(num-1), ios::beg);
         //Read in the player information, including their name and balance 
         player_info.read(reinterpret_cast<char *>(&play),sizeof(play));
         cout<<"Welcome Back "<<play.name<<"!"<<endl;
         //Determine if the user would like to purchase more coins 
         cout<<"Your current balance is $"<<play.balance<<", would"
                 " you like to buy in more? y/n"<<endl;
         char x; cin>>x;
         if (tolower(x) == 'y'){
             cout<<"Enter how much more you like to buy in or type 0 for none "<<play.name<<endl;
         //Get the buy in as a cstring to prevent run time errors, convert to int using atoi.     
         char y[6];cin.ignore();  cin.getline(y,6);
         play.balance+=atoi(y);} //Add the buy in to the total player balance 
         cout<<"Your current balance is $"<<play.balance<<endl;
                  player_info.close();
                  
    /*if the user is new, call the greeting function and input the name
     to the file*/     
    }else{
    //Begin greeting, get user name 
    displayGreeting(play);
    cout<<"****************************************************************\n";
    //Determine how much the player wants to buy into game
    cout<<"How much would you like to buy in "<<play.name<<" ?"<<endl;
    cin>>play.balance;
    }
}


/****************************************************************************
                          displayGreeting    
 ***************************************************************************
 
 Purpose : to introduce the user to the game, get the user name to create
 a more personal experience, and then output the rules depending on if the
 user knows how to play or out
 
 Input : user name, answer
 Output: Rules of the game 
 
 Return --> user name to the main program
 *******************************************************************************/

void displayGreeting(Play &play){
    //Declare Variables
    char answ; //sentinel value used to trigger rules or not

    cout<<"Your name and balance will be saved when you are finished....\n";
    cout<<"What is your name anyway? "<<endl;
    cin.getline(play.name,25); //Get user name, to create a more personal experience
    cout<<"Ah! nice to meet you "<<play.name<<", you have a lovely name";
    cout<<"\nAnyways, Im going to assume you know how to play BlackJack"
            " as you would be foolish\nto play against me without any "
            "experience... "<<endl;
    cout<<"Would you like the rules explained? y/n"<<endl;
    cin>>answ;//Only display rules if user does not know how to play to avoid
   
    if (tolower(answ) == 'y'){
    //Program explains rules of the game    
        cout<<"Well this is awkward... \n anyways ill try to explain my best,\n"
                "and do not expect me to go easy on you just because you are a "
                "rookie... "<<endl;
       cout<<"****************************************************************\n";
        cout<<"Basically the point of the game is to get to 21 or as close as"
                "possible without going over,\notherwise you lose"
                "\n,in addition, if my card total is higher than yours"
                " you also lose \n";
       cout<<"****************************************************************\n";
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
      cout<<"****************************************************************\n";
        cout<<"Got it? GOOD! Let me know when you are ready to play"<<endl;
    }else { //program skips to here if user knows the rules
        cout<<"Thank gosh, I hate explaining rules...⊙﹏⊙\n";
    }
}

/****************************************************************************
                          GetShuffle  
 ***************************************************************************
 Purpose : Receive the array that represents a deck of cards, initialize it 
 * with numbers 2-54, then shuffle the number around, stimulating
 * the shuffling of a deck of cards
 
 Input : the array deck[CARDS] - deck of cards 
 
 Return --> the shuffled array back to main
 ******************************************************************************/


/****************************************************************************
                          hitORstay  
 ***************************************************************************
 Purpose : To determine if the user would like to hit or stay based on their
 * current card value, if hit, loop until user busts, hits 21, or decides to 
 * stay
 
 Input : The card drawn by player, the player card total from previous two cards,
 * the deck, and the card # of the deck. 
 
 Return --> void
 ******************************************************************************/
void hitORstay(Curhand &player,Deck &cards){
int b =0;      //sentinel value to break out of player card loop
        do{
            char nxtC;  //variable used to determine if user wants to hit or stay
           
            cout<<"Would you like to "
            "hit or stay? h/s"<<endl;
            cin.ignore();
            cin.get(nxtC);
            
            if (tolower(nxtC) == 'h'){
            player.cards = cards.deck[cards.count]; cards.count++;
            valueCards (player);
            cout<<player.cardTot<<" is your new card total"<<endl;
            cout<<"**********************************************************\n";
           
            }if (player.cardTot>21 || player.cardTot == 21 || tolower(nxtC)=='s'){ 
                b = 1;
      cout<<"****************************************************************\n";
            }
        }while( b != 1);

}

/****************************************************************************
                          Get ValueCards   
 ***************************************************************************
 Purpose : Receives the integer value of each card, adds them to the card
 * total, and then assigns a string value to the card in addition to a suit
 
 Input : card total, integer card value
 Output: Card value and suit in the form of a string 
 
 Return --> card total to the main program for further calculation
 *******************************************************************************/
