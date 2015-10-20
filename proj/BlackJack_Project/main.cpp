/* 
 * File:   main.cpp
 * Author: Amul Bham (Project 2 - 46090)
 * Purpose: To play Blackjack against 
 * A.I. implementing new and more efficient methods
 * learned in class
 * Created on July 15, 2015, 3:35 PM
 */
//System Libraries
#include <iostream>     
#include <algorithm>    
#include <ctime>        
#include <cstdlib>
#include <fstream>

using namespace std;

//Global Constants

//User Libraries

//Function Prototypes
string displayGreeting(string); //function for greeting player
void valueCards(int& ,int);       //function add card values + suit
int genRand (int i) { return rand()%i;} //function to generate a random number
void getShuffle(int deck[],int cards); //creates deck and shuffles cards
void getUser(string& name,int& bal); //determines user, initiates greeting
void hitORstay(int& pcard, int& pCardt,int deck[],int& z);//handles logic for hitting/staying

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
     srand (time(0));
     string name;   //name of player
     int pcard;     //user cards
     int dcard;     //dealer cards
     int pCardt=0;  //user card value total
     int dCardt=0;  //dealer card value total
     const int CARDS = 52;
     int deck[CARDS];//deck of cards with 53 values
     int y;         //set = to the user balance
     char answ;     //sentinel value used to trigger new hand or end game
     int bal=0,bet;   //user balance, and amount user wants to bet for a hand
     int z = 0;     //variable used to track cards in deck
     
     /*call the get user function to determine if the player is
      continuing or starting a new game*/
     getUser(name,bal);
     
     //set y = to the user balance at start of hand
     y = bal; 
     
  //game loop begins here   
  do{   
   
    string trig;   // Trigger to begin game
    cout<<"Press any key and hit enter when you are ready to play "<<name<<endl;
    cin>>trig;
    cout<<"****************************************************************\n";
    
    //Initialize the deck with values 2-53.
    if (z==0 || z>40){ //only shuffles at beginning or when deck is running low
        getShuffle(deck,CARDS);
    } 
    
    //Game begins here by asking how the user would like to bet on first hand
    cout<<"How much would you like to bet?"<<endl;
    cin>>bet;
    bal -=bet; //subtract bet from starting balance
    cout<<"Okay sounds good, your remaining balance is $"<<bal<<endl;
    cout<<"****************************************************************\n";
    
    //first two player cards are dealt
    cout<<"Your first two cards are.... "<<endl;  
    for(int i = 0;i<2;i++){
        pcard = deck[z];z++; //z incremented after ever card draw for next card
        valueCards (pCardt,pcard);
    }  
    cout<<name<<" your hand equates to "<<pCardt<<endl<<endl; //first two card total
    cout<<"****************************************************************\n";
    
    int win = 0; /*value to guide program NOT to display 21 message again if 
                  user draws a 21 on first two cards*/
    if(pCardt==21){ 
        cout<<"Congratulations you got blackjack! ☜(˚▽˚)☞"<<endl;
        cout<<"****************************************************************\n";
         win = 1; //prevents a repeat 
    }
    
    //Then the dealer draws their first card value
    cout<<"My first card is a.... "<<endl;
    dcard = deck[z];z++;
    valueCards(dCardt,dcard);
    cout<<"My hand so far equates to "<<dCardt<<endl; //dealer first card total
    cout<<"****************************************************************\n";
    
    /*Player then must decide to hit or stay, loop continues until
     player busts, hits a 21, or decides to stay */    
    if (win != 1){ //only runs if player has not already hit a 21    
        hitORstay(pcard,pCardt,deck,z);
    }
     
    /*At this point, the program determines if the user has busted or reached
    blackjack, if user busts, dealer hand is skipped as the user has lost,
    else the dealer hand continues until dealer hits 17 or goes over 21*/
     if(pCardt==21 && win !=1){
        cout<<"Congratulations you got blackjack! ☜(˚▽˚)☞"<<endl;
        cout<<"****************************************************************\n";
     }else if(pCardt>21){
        cout<<"Busted! You lose! ¯|_(ツ)_/¯ "<<endl;
    cout<<"****************************************************************\n";
   
    /*Dealer hand continues until dealer hits 17 or higher or goes over 21,
     only executes if player has not busted*/
    }if (pCardt <=21){
        cout<<"And now, the rest of my hand..."<<endl;
        do{ //Loop dealer hand till card total at 17 or higher
          dcard = deck[z];z++;
          valueCards(dCardt,dcard);
        }while(dCardt <17);
        
   cout<<"My Hand equates to "<<dCardt<<endl;  //dealer card value total
   cout<<"****************************************************************\n";
  
   /*Program then determines who had the higher card value total,
  if user wins, they win twice the amount they bet, if they lose user
  loses their bet, if a tie, bet is returned to the user*/
        if (dCardt<pCardt || dCardt>21){ //if user value is higher or dealer busts
            cout<<"Congratulations "<<name<<
                " you won the hand ☜(˚▽˚)☞ "<<endl;
            bal +=bet *2; //user wins 2 * the amount they bet
        }else if (dCardt>pCardt && dCardt<=21){ //if dealer value is higher
            cout<<"Thank you for playing "<<name<< ", but you lose (◑‿◐)"<<endl;
        }else if (dCardt == pCardt){ //if card values are equal
            cout<<"Draw!"<<" I guess that means you technically "
                    "aren't a loser..."<<name<<endl;
            bal +=bet; //if draw, user gets the bet back
        }
    }  
  /*Program then lets the user know of their remaining balance to inform them
    on their winnings/losings or if they are the same, and prompts the user
    if they would like to play a new hand*/
    cout<<"****************************************************************\n";
    cout<<"Your remaining balance is $"<<bal<<endl; 
    
    cout<<"****************************************************************\n";
    cout<<"Do you want to play another hand, or walk away now?"<<endl;
    cout<<"y/n \n";
    cin>>answ; 
    
    /*set dealer and player card totals back to 0 for new hand*/
    dCardt = 0; 
    pCardt = 0;
   
 /*if user would like to play a new hand, program loops back to making a bet
  * ,asks the user for a new bet, and the rest of the program
    proceeds as normal, when card 40 (z=40) is reached, the deck shuffles*/
 }while(answ == 'y' || answ == 'Y');
 
 //Output the results of the game, if the user has lost or gained money
 if (bal>=y){
 cout<<"****************************************************************\n";
 cout<<"You winnings for the day are $"<<bal - y<<"\ngo buy yourself"
         " something nice "<<name<<endl; 
 }else {
 cout<<"Looks like you lost $"<<y - bal<<" today, better luck next time "<<name<<endl;
 } 
     
     //write the remaining balance to the balance folder
     ofstream balance;
     balance.open("balance.txt");
     balance << bal ;
     balance.close();
    
    //Exit stage right    
     
    return 0;}

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

void getUser(string &name, int &bal){
    char c;
    cout<<"Would you like to continue(c) or start a new game(n)? c/n"<<endl;
    cin>>c;
    /*if continuing, read file for name and balance*/
    if (c == 'c' || c=='C'){
         ifstream name_file;
         name_file.open("name.txt");
         name_file >> name;
         name_file.close();
         ifstream balance;
         balance.open("balance.txt");
         balance >>bal;
         balance.close();
         cout<<"Welcome Back "<<name<<"!"<<endl;
         cout<<"Your current balance is $"<<bal<<", would"
                 " you like to buy in more? y/n"<<endl;
         char x; cin>>x;
         if (x == 'y' || x == 'Y'){
             cout<<"Enter how much more you like to buy in "<<name<<endl;
         int x;  cin>>x;
         bal +=x;}
    /*if the user is new, call the greeting function and input the name
     to the file*/     
    }else{
    //Begin greeting, get user name 
    name = displayGreeting(name); 
    ofstream name_file;
    name_file.open("name.txt");
    name_file<<name;
    name_file.close();
    cout<<"****************************************************************\n";
    //Determine how much the player wants to buy into game
    cout<<"How much would you like to buy in "<<name<<" ?"<<endl;
    cin>>bal;
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

string displayGreeting(string name){
    //Declare Variables
    char answ; //sentinel value used to trigger rules or not
    
    cout<<"                  BlackJack ☜(˚▽˚)☞"<<endl;
    cout<<"****************************************************************\n";
    cout<<"Welcome to the Casino Bham! \n My name is Amul (◕‿◕) and i will "
            "be your dealer today!";
    cout<<"What is your name? ";
    cin>>name; //Get user name, to create a more personal experience
    cout<<"Ah! nice to meet you "<<name<<", you have a lovely name";
    cout<<"\nAnyways, Im going to assume you know how to play BlackJack"
            " as you would be foolish\nto play against me without any "
            "experience... "<<endl;
    cout<<"Would you like the rules explained? y/n"<<endl;
    cin>>answ;//Only display rules if user does not know how to play to avoid
   
    if (answ == 'y' || answ == 'Y'){
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
    return name; //return name so rest of program can use user name
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

void getShuffle(int deck[],int cards){
    srand (time(0));
    for(int x=0;x <cards;x++){
        deck[x]= x+2;
        }
     /*Shuffle the deck for all values, using a random number
     to determine how its shuffled*/ 
        random_shuffle(&deck[0], &deck[52],genRand);
}
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
void hitORstay(int &pcard,int &pCardt,int deck[],int &z){
int b =0;      //sentinel value to break out of player card loop
        do{
            char nxtC;  //variable used to determine if user wants to hit or stay
           
            cout<<"Would you like to "
            "hit or stay? h/s"<<endl;
            cin>>nxtC;
            
            if (nxtC == 'h' || nxtC == 'H'){
            pcard = deck[z];z++;
            valueCards (pCardt,pcard);
            cout<<pCardt<<" is your new card total"<<endl;
            cout<<"**********************************************************\n";
           
            }if (pCardt>21 || pCardt == 21 || nxtC=='s' || nxtC=='S'){ 
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

 void valueCards(int &cardTot,int card){       
        string faceValue; //face value of card
        string face;      //suit of the card
       
    /*The suit of the card is determined by the value of the card(2-54), 
     then a value is subtracted so the card falls between 2-14*/
          if (card<=14){ 
              face = "Hearts";
          }else if (card>14 && card<=27){
              card -= 13; 
              face = "Diamonds";
          }else if (card>27 && card<=40){
              card -= 26; 
              face = "Cloves";
          }else if (card>40){
              card -=39;
              face = "Spades";
            }
        /*switch statement used to calculate card total, face value is assigned*/
        switch(card){ 
            case 2:
                cardTot+=2;
                faceValue="Two";
                break;
            case 3:
                cardTot+=3;
                faceValue = "Three";
                break;   
            case 4:
                cardTot+=4;
                faceValue = "Four";
                break;    
            case 5:
                cardTot+=5;
                faceValue = "Five";
                break;
            case 6:
                cardTot+=6;
                faceValue = "Six";
                break;
            case 7:
                cardTot+=7;
                 faceValue = "Seven";
                break; 
            case 8:
                cardTot+=8;
                faceValue = "Eight";
                break;
            case 9:
                cardTot+=9;
                faceValue = "Nine";
                break;    
            case 10:
                cardTot+=10;
                faceValue = "Ten";
                break; 
            case 11:
                cardTot+=10;
                faceValue = "Jack";
                break; 
            case 12:
                cardTot+=10;
                faceValue = "Queen";
                break; 
            case 13:
                cardTot+=10;
                faceValue = "King";
                break;
            /*since ace represents two values(1 & 11), program must determine
            which to represent, if card total is below or equal to ten, it
            represents an 11 else it represents a 1*/   
            case 14: 
                faceValue = "Ace";
                if(cardTot>10){
                    cardTot+=1; 
                }else if (cardTot<=10){
                    cardTot+=11;}
    }
        //Output the face value and the suit of the card
        cout<<faceValue<<" of "<<face<<endl;
        
}

