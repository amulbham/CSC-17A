/* 
 * File:   game.cpp
 * Author: Amul.bham
 * Purpose: The Main Purpose of this class was to control the game flow 
 * and logic of the game of BlackJack. This allowed my main function to focus on
 * the more abstract dealings of the program such as guiding which 
 * part of the game is to be executed first, while the game class
 * handled all the minor details and logic points involved in each 
 * part of the game. 
 * - In the game class, their lies a vector of player classes and a
 * instance of a deck class which I decided to aggregate into the game class
 * as any instance of a blackJack game will have to have players and a deck
 * of cards, therefore it was more logical to define the players within
 * the class based on how many players are playing for that given session
 * 
 * - A game of blackjack has -> players, and also has -> a deck of cards and a dealer
 * 
 * - By allowing my main to control the higher abstract game flow, the game 
 * class controlled how each class interacted with each other and passed
 * values of each player to the different parts of the game. The main 
 * was used to control what parts of the black jack game were to be executed
 * in what order. 
 * 
 * - This kept the main as sort of a make file in that it simply controlled 
 * what parts of the game class to execute, this made it so in the future, 
 * I could add other game classes and use the main again to control that game 
 * as well, therefore allowing players to select which game they would want to play
 * 
 * Created on December 9, 2015, 12:14 AM
 */

//Libraries
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


/*Default Constructor - > must be defined with the amount of players
 playing as a game cannot be started without players
 
 -The number of players is set, and the x vector has an instance of the player
 class put inside it equal to the number of players, each class holds each players
 information such as balance, name, game status, etc.
 
 - After, each instance of player, or each player, is taken through a series
 of questions to determines if they are new or returning in the getInfo function
 
 -This is all done when the game instance is created, therefore setting the game
 up with the proper amount of player instances.*/
blackJack::blackJack(int n) {
     numP = n;
     x.clear(); //Clear the array incase of any faulty memory
     //Vector allows for dynamic creation of player instances
     while(x.size()<numP ){
         x.push_back(player());
     }
     //Loop through each player and obtain their information, if they are
     //returning, then read their information in from the player.txt file
     for(int i =0; i<x.size();i++){
         getInfo(x[i]);
     }
    
}
/*After the player info is obtained and assigned to each player instance, 
 each player must place a bet for the upcoming hand
 - Used a char string to get the bet to account of commas and other user input errors
 - The bets are set for each player bet variable as they will be needed as the end
-Used atol to convert the char string after it has been approved*/
void blackJack::setBets(){
    char b[7]; //Used to temp hold the bet place by each player
    cin.ignore();
    //Loop through each player and get their bets for the hand
    for(int i =0; i<x.size();i++){
        cout<<x[i].name<<": "<<endl;
        bet:
        cout<<"Please enter a bet for the current hand ($50.00 min): $"; 
        cin.getline(b,7); 
        //If their bet is invalid, loop back so they can place a valid bet
        if(atol(b)<50 || atol(b)>x[i].giveBal()){
        cout<<"Invalid amount! Bet must be at least $50.00 and no greater than your total balance!"<<endl;
        cout<<"Your balance is : $"<<x[i].giveBal()<<endl;
        goto bet;
        }else{
        //Set the player bet calling the setBet player function, using atol for conversion    
        x[i].setBet(atol(b));    
        cout<<"Thank you for your bet"<<endl;
        }
        //Display a border after each player for clarity
        disBord();
    }
    cout<<"Good Luck to all Players!"<<endl;
}

/*The Deal Card Function:
 Used to handle the logic and execution of the first part of the game
 which included dealing the cards for each player and finally dealing 1
 card for the dealer. 
 
 -First each player is looped through twice with a card being drawn from the 
 deck each time, after the DrawCard() function prints out each card value,
 the total is returned and added to the players overall card total
 
 - The checkWinLoss function of the game is called to check for any special 
 cases, for the first hand it would only be a 21 for any player, set the status
 for each player , and then give them back their total for clarity
 
 -After each player is dealt, the dealers first card is revealed, and 
 total printed, from here the next part of the game is ready to execute*/
void blackJack::dealCards(){
    /*Create a deck of cards at the start of the game, makeDeck() function
     * of card class is setup to handle all the logic for creating the deck */
    deck.makeDeck();
    cout<<"Now Dealing first two cards for each player..."<<endl<<endl;
    int card=0;
    /*Loop through each player, printing their total after each turn,
     used a double for loop, first one to loop through each instance of 
     players, and second to loop through 2 cards for each player*/
    for(int i = 0; i<x.size();i++){
       cout<<x[i].name<<": "<<endl; 
       for(int j =0; j<2; j++) {
       card = deck.drawCard();
       x[i].setCardT(card);
       }
       cout<<"Total: "<<x[i].giveTotal()<<endl<<endl;
    }
    /*Check for any special conditions after cards are drawn*/
    checkWinLoss();
    //Proceed to dealer first card - display total
    cout<<endl;
    disBord();
    //Set the dealer card total in the instance of the dealer class
    cout<<"Proceeding to dealer hand...."<<endl;
     card = deck.drawCard();
     dealer.setCardT(card);
     cout<<"Dealer Total: "<<dealer.giveTotal()<<endl;
     if (dealer.giveTotal() > 21) dealer.setStat(3);
     else if (dealer.giveTotal() == 21 || dealer.giveTotal() >= 17) dealer.setStat(2);
     else dealer.setStat(1);
}

/*The hisORstay function was used to handle all the logic of each player
 deciding to hit or stay. Allowed my main to simply execute this part of the program
 and kept the complicated logic bundled away from the abstract logic in my main
 
 - Based on the result of each player hand, their status must be updated accordingly
 to track if they lost, hit a 21, below 21 , etc. Allowed me to track 
 how each player should be dealt with in the final part of the program that determines
 the winners
 */
void blackJack::hitORstay(){
    //Loop through each player
    for(int i = 0; i <x.size();i++){
       char d;
       int card; //Used to temp store the card value returned from the deck
       //Display the current player name
       cout<<x[i].name<<endl;
       /*Only ask for hit or stay if their status is = 1 (continue)
        if they had a 21 from the first cards, then they are skipped*/
       if (x[i].giveStat() == 1){
         /*Continue looping until player status changes to 2 (finished)
          which means they chose to stay, busted, or hit a 21*/
           do{
            cout<<"Card Total: "<<x[i].giveTotal()<<endl;
            cout<<"Would you like to "
            "hit or stay? H/S"<<endl;
            //Determine if user wants to hit or stay
             cin.get(d); cin.ignore();
             //If they hit, draw a new card, add card value
            if (tolower(d) == 'h'){
           card = deck.drawCard();
           x[i].setCardT(card);
           //if not then set their status to 2 for finished and go to the next player
            }else x[i].setStat(2);
       }while(x[i].giveStat() == 1); 
       }
       //If the player hits a 21 or busts, let them know
       if (x[i].giveTotal() == 21){
           cout<<"BlackJack!"<<endl;
       }else if (x[i].giveTotal() > 21){
           cout<<"You Busted!"<<endl;
       }
       //Display the final card total for each player
        cout<<"Final Card Total: "<<x[i].giveTotal()<<endl;
        disBord(); 
    }
    //Change status again based on outcome of the hand
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
    cout<<"Results: "<<endl;
    for (int i = 0; i<x.size();i++){
        cout<<endl<<x[i].name<<":"<<endl;
        if (x[i].giveTotal()== 21){
            cout<<"you hit a blackjack, congratulations!"<<endl;
            x[i].setStat(2);        
        }else if (x[i].giveTotal() > 21){
            x[i].setStat(3);
            cout<<"you busted! Sorry!"<<endl;
            cout<<"Card Total: "<<x[i].giveTotal()<<endl;
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
    cout<<"Results of Hand and Updated Balances: "<<endl;
    disBord();
    for (int i = 0; i<x.size(); i++){
        if (x[i].giveStat() == 5){
            x[i].win();
        cout<<x[i].name<<" you have won!"<<endl;
        cout<<"Balance: $"<<x[i].giveBal()<<".00"<<endl;
        }else if (x[i].giveStat() == 3){
            x[i].loss();    
        cout<<x[i].name<<" you have lost!"<<endl;
        cout<<"Balance: $"<<x[i].giveBal()<<".00"<<endl;
        }else{
        cout<<x[i].name<<" you have tied the dealer!"<<endl;
        cout<<"Balance: $"<<x[i].giveBal()<<".00"<<endl;
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
            cout<<"Amount(100.00 min::10,000.00 max): "; cin>>y; cin.ignore();
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
    player_info.open("player.txt", ios::in | ios::binary);
    curr.setNew(0);  curr.setBin((sizeof(player_info)/sizeof(temp))+1);
    player_info.close();
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
    cout<<"Basically the point of the game is to get to 21 or as close as\n"
                "possible without going over, otherwise you lose"
                "\nIn addition, if my card total is higher than yours"
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



