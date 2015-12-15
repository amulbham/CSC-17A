/* 
 * File:   game.cpp
 * Author: Amul.bham
 * Purpose : can be found in .h file
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
         
         //push back a new player object for each player
         x.push_back(player());
     }
     //Loop through each player and obtain their information
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

/*dealerHand -> The 3rd part of the blackJack gameflow
 After each player hand is finished in the previous functions, the rest
 of the dealer hand needed to finish
 
 I decided to create a new function for it as it had a lot of new logic in terms
 of how to deal with the value and when to stop the hand.
 
 The dealer has to keep drawing until they are at 17 or higher,
 so I just used a do while loop to keep drawing and adding cards from
 the deck instance until it reached 17 or higher
 
 After, the status of the dealer must be checked for special conditions such as 21*/
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
    //If dealer is busted, set the status to 3 (loss)
    if (dealer.giveTotal() > 21){
        dealer.setStat(3);//set status to loss
        cout<<"Dealer has Busted!"<<endl;
    //If dealer has blackjack, set status to 2, let player know    
    }else if (dealer.giveTotal() == 21){
        dealer.setStat(2);
        cout<<"Dealer has a BlackJack!"<<endl<<endl;
    //No special conditions, set status to 2 for check with other players    
    }else dealer.setStat(2);
}

/*checkWinLoss function -> Used to check the player hand for any special
 conditions such as a bust or a 21, which in turn allows the program
 to know how to deal with each player in the upcoming functions
 
 -> Made it separate as it was crucial to the logic of my game 
 and had to be executed after each player turn
 
 -> Having a function to check statuses always ensured that each player
 was in the proper 'state' for the next part of the program
 for Ex: if a player has a status of 3 (which mean they busted) the program
 will know to not ask them if they would like to hit or stay, or to even
 check if they won at the end as all players with status 3 have automatically lost*/
void blackJack::checkWinLoss(){
    disBord();
    //Display results after each hand, any special conditions
    cout<<"Results: "<<endl;
    for (int i = 0; i<x.size();i++){
        cout<<endl<<x[i].name<<":"<<endl;
        if (x[i].giveTotal()== 21){
            cout<<"you hit a blackjack, congratulations!"<<endl;
            x[i].setStat(2); //set status to finished with hand       
        }else if (x[i].giveTotal() > 21){
            x[i].setStat(3); //set status to loss if over 21
            cout<<"you busted! Sorry!"<<endl;
            cout<<"Card Total: "<<x[i].giveTotal()<<endl;
        }else { //if not a bust or 21, set to 1 for can continue
            x[i].setStat(1);
            cout<<"Card Total: "<<x[i].giveTotal()<<endl;
    }
        cout<<endl;
}
}

/*The checkWinLoss was used to set the status of each player after each part 
 of the game. However, I still needed a separate function to actually make
 * meaning of those statuses. 
 
 checkWinner -> used to interpret the meaning of each players status
 after the hand has finished, everything checked against dealer status, and a final
 * win, loss, or tie status are initialized -> after, final results can be displayed
 
 If dealer has a blackjack, all players who wont -> lose
 If dealer is over 21, all players who don't already have a status of 3 ->win
 If dealer and player are set to status of 2, then the values are compared, 
 whoever has a higher card value wins
 
 -Since each players status of winning or losing is separate from the other
 players, it must be determined independently with each players
 circumstances taken into account
    -Ex: If a player busts, and the dealer busts after, the player still loses,
 because the player busted first, however any other players who did not bust will win*/
void blackJack::checkWinner(){
   for(int i = 0; i< x.size(); i++){
      //First, if any players are over 21, set them to loss prior to checking anything  
     if (x[i].giveTotal() >21) x[i].setStat(3);
      
      //If they have a valid hand, check against each possible dealer hand
     //set their status for win,loss,or tie, the final status of the hand
     if(x[i].giveStat() != 3){
          //If dealer has 21, any player who does not, is set to loss
       if (dealer.giveTotal() == 21){
            if (x[i].giveTotal() != 21 ){
                x[i].setStat(3); //set for loss if !21
            }else x[i].setStat(4); //If they do, then set to 4 for draw
            
       //If the dealer has not busted, or 21, then the dealer card total
       //must be checked against each player who has not busted     
       }else if (dealer.giveTotal() < 21 ){
            if (x[i].giveTotal()> dealer.giveTotal()){
                x[i].setStat(5); //player total is higher = win, if = then tie
            }else if(x[i].giveTotal() == dealer.giveTotal()){x[i].setStat(4);}
             else x[i].setStat(3); //If lower, then the player is set to a loss
       //If dealer has busted, then every player who has NOT busted, wins
       }else if (dealer.giveTotal()> 21) x[i].setStat(5);
   } 
    }
}
/*After the status of each player is interpreted and checked against the dealer, 
 a final status is set. Finally the results are ready to be displayed for the hand
 in text format, updated balances are displayed after bets are taken into account,
 and the hand ends
 
 showResults -> I needed a function specifically for 'wrapping up' the hand
 * and to give a overall report to the players of the implications
 * 
 * -I tried to make only for displaying results, tried not to calculate anything
 * new in this functions
 * 
 * - Based on the final status of each player(1,2,3), they are told of the results
 * and their new balances are calculated accordingly */

void blackJack::showResults(){
    cout<<"Results of Hand and Updated Balances: "<<endl;
    disBord();
    //Loop through each players status
    for (int i = 0; i<x.size(); i++){
        //5 = win; bet is added to player balance
        if (x[i].giveStat() == 5){
            x[i].win();
        cout<<x[i].name<<" you have won!"<<endl;
        cout<<"Balance: $"<<x[i].giveBal()<<".00"<<endl;
        //3 = loss, bet subtracted from balance
        }else if (x[i].giveStat() == 3){
            x[i].loss();    
        cout<<x[i].name<<" you have lost!"<<endl;
        cout<<"Balance: $"<<x[i].giveBal()<<".00"<<endl;
        //4 = tie; player receives bet back
        }else{
        cout<<x[i].name<<" you have tied the dealer!"<<endl;
        cout<<"Balance: $"<<x[i].giveBal()<<".00"<<endl;
        }
        //output a border after each player so the results are clear 
        disBord();
    }
}

/*After each hand, the player is given the option to play a new hand
 or exit the game, if they wanted to play a new hand, I needed to make sure
 their player instance was set up again for a new hand
 
 newHand -> Created to reset the dealer and each player
 instance card total for the next hand, also checks if any of the players
 have run out of chips, if so, they must buy in more
 
 Basically I needed to ensure after each hand, the players and dealer
 variables were reset to prevent overlap between hands
 
 -Only certain variable needed to be reset, others such as the player.name and balance
 were maintained, therefore you could not just create a new instance of
 the blackJack game as then you would lose player information from previous hand*/
void blackJack::newHand(){
    long int y; //Temp hold buy in value 
    //Call the dealer reset function first, this resets all the crucial 
    //dealer variables
    dealer.reset();
    /*Then loop through each player, reset their variables, and determines
     if they ran out of money and need to buy in, set their new balance*/
    for (int i = 0; i< x.size(); i++){
        x[i].reset(); //reset each players card values
        if (x[i].giveBal() < 0){
           do{ //Loop while invalid amount 
            cout<<x[i].name<<endl;
            cout<<"You must purchase more chips to continue as you are below 00.00!"<<endl;
            cout<<"Amount(100.00 min::10,000.00 max): "; cin>>y; cin.ignore();
           }while(y < 100 || y> 10000 );
           x[i].setBal(y); //Set players new balance
        }
    }
}

/*disBord() -> used to separate off information and parts of the game for the player
 to ease with clarity and readability, made it easier to insert border versus
 typing out a border each time I needed one, also kept the look 
 of the program more of a similar feel*/
void blackJack::disBord(){
cout<<"****************************************************************"<<endl;
}

blackJack::blackJack(const blackJack& orig) {
}

/*After a new instance of a player class is created, the player information
 for that instance must be obtained, based on if they are new or returning, 
 the program must make a wealth of choices to determine how to obtain the 
 * player information for that given instance
 
 getInfo -> Used to handle getting all player information, each player instance 
 * if passed through it, determined if the player is new or returning
 * 
 * -> From here, the program either reads out the player information on file
 * and asks the user to select a account - this account number is = to the binary
 * location number of each player in file, set at the end of each game
 * OR -> obtains the new players information, assigns it to their instance, 
 * and then set their binary number position to the total size of the file + 1;
 * 
 * -Also, if a player is already loaded into the game by someone else, the function
 * must check that no 2 players are on the same account 
 * 
 * -I used a fstream object to read in the player information, I used a temp
 * structure to store each player information, display it, and then increment to the
 * next section (all done as a binary file, as I had to store the name, and int balance)
 * - If player returning, I read in their information from structure to 
 * their player class
 * 
 * - At the end of game, their names and balances are stored again in the temp
 * structure, 1 by 1, and then written back into the file "player.txt" in spot 
 * = to their binary number position
 */

void blackJack::getInfo(player &curr){
    
    //Variables used to store player decisions
    bool t = true;
    char c;
    //Determine if the user is returning or if it is their first time 
    _rORn:
    cout<<"Player "<<cot+1<<":"<<endl;
    cout<<"Are you returning or a new player? (r/n)"<<endl;
    cin>>c; cin.ignore(); 
    //Needs to be valid as this part is crucial in determining how to deal with that player
    if (tolower(c) != 'r' && tolower(c) != 'n') {
        cout<<"Invalid option!"<<endl; goto _rORn;
    } 
    cot++;
    int count = 1;
    /*if continuing, read all the players currently in the file and ask
     the user to select which account they would like to play on
     * status is set to NOT NEW, program will rewrite this players new 
     * information in the same spot in file AFTER game finishes */
    if (tolower(c) == 'r'){
        //Open the player file for input, and as a binary file(has structures)
        player_info.open("player.txt", ios::in | ios::binary);
        if (!player_info) {cout<<"Error opening file!"<<endl;}
        //Open the player file for binary input 
        cout<<"The current players on record are ..."<<endl;
        disBord();
        //Static cast the binary data into the temp structure for the size of the
        //entire temp structure
        player_info.read(reinterpret_cast<char *>(&temp), sizeof(temp));
        
       /*Read out all the players, incremented by byte size, each player
        information being stored in a structure, until the end of the file is reached*/
        while(!player_info.eof()){
            cout<<"Player "<<count<<endl;
            cout<<"Name: "<<temp.name<<endl;
            cout<<"Balance: $"<<temp.bal<<endl;
            player_info.read(reinterpret_cast<char *>(&temp), sizeof(temp));
            count++;
            disBord(); //display a border between each player information
        }
        //Close the file to prevent memory leaks 
         player_info.close(); int ply; //temp value to store player # input
         //Allow the user to choose an account to play on 
         do{ //Loop until value is valid, no repeats are allowed
         cout<<"Enter the player number of the account you would"
                " like to play on: ";
         cin>>ply; ply -=1;
         //Check against other players, make sure 2 people not on same account
         for(int i =0; i<x.size();i++){
             if(ply == x[i].givePos()){
                 t = false;//set loop condition
                 cout<<"This account is already in use!"<<endl;
                 break; //If same, break here, start loop again
             }else {t = true;}
         }
         //If ply is valid, t set to true, loop ends
         }while(!t);
         
         //Read in the player information based on the account choosen 
         player_info.open("player.txt", ios::in|ios::out|ios::binary);
         //Seek to the memory location of the user account, based on the num
         player_info.seekg(sizeof(temp)*(ply), ios::beg);
         //Read in the player information, including their name and balance 
         player_info.read(reinterpret_cast<char *>(&temp),sizeof(temp));
         /*After appropriate binary information for given player is determined
          read it into the temp structure for temp storage*/
         
         /*Then copy each temp structure variable to the required variables
          in the given players player instance - read in name, balance, and binary num*/
         strcpy(curr.name, temp.name); curr.setBal(temp.bal);
         curr.setBin(ply); curr.setNew(1); //Set player status at NOT NEW
         
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
         //Remind user of updated balance, close player file
         cout<<"Your current balance is $"<<curr.giveBal()<<endl;
         player_info.close();
                 
    /*if the user is new, obtain new player information, set player status
     to NEW, this will tell the program to APPEND the player.txt file 
     to create a new section for the new player versus overriding 
     another players file*/  
         
    }else{
        //Open the file just to get the size of it in bytes
    player_info.open("player.txt", ios::in | ios::binary);
    curr.setNew(0);  curr.setBin((sizeof(player_info)/sizeof(temp))+1);
    player_info.close();
    char r;
    //Name stored as cstring as strings cannot be written to file
    cout<<"A new player! Terrific! First I'll need your name: "<<endl;
    cin.getline(curr.name,25); //get the new players name
    
    //If they want to hear rules, call disRules function
    cout<<"Would you like to hear the rules? (Y/N)"<<endl;
    cin.get(r);cin.ignore();
    if(tolower(r)== 'y'){
        disRules();
    }
    disBord();
    //Determine how much the player wants to buy into game, loop till valid amount
    _buyin:
    cout<<"How much would you like to buy in?($100.00 minimum::$10,000.00 limit)"<<endl;
    long int b;
    cin>>b; if (b<100 || b>10000) {cout<<"Invalid amount!"<<endl;goto _buyin;}
    curr.setBal(b); //set the new players balance in their instance 
    }
    disBord();
}
/*After players are finished playing, I needed a function to handle the logic
 * for writing the updated players information back into player.txt
 * 
 * writeInfo -> Loops through each player and does the followings
 * 
 * 1. copy vital player information(balance,name,binary position) into a temp
 * player_info structure for storage
 * 
 * 2. Write player data(stored in a structure) into the file for the size of 
 * structure and in binary so we can store separate instances of different data types 
 * 
 * 3. if player is new -> append the file -> create new instance in the file 
 *  if player is returning -> overwrite the position in the file = the players
 *  binary number position * size of the structure(the size of the temp structure
 * is basically the measurement for incrementing between players in the
 * binary file, thus their position can always be determined given that a value is tracked
 * for each player of their position), this will seek the file 
 *  at the spot that the player previously had their information stored
 *  (Random Access Memory), and only overwrite their previous data  
 */
void blackJack::writeInfo(){
 for(int i =0; i<x.size(); i++){
     //Copy the name, position, and updated balance to the temp structure for storage
     strcpy(temp.name, x[i].name); //use string copy for char string instead of looping
     temp.bal = x[i].giveBal();
     temp.bN = x[i].givePos();
     
     //Open up player.txt file for output, and in binary
     player_info.open("player.txt", ios::in | ios::out | ios::binary);
     
    //If a players giveNew() functions is true, their information is appended
     //to the file
     if(x[i].giveNew()== true) {
        player_info.close();//close and reopen the file for append mode 
        player_info.open("player.txt",ios::binary| ios::app);
        player_info.write(reinterpret_cast<char *>(&temp),sizeof(temp));
     //For returning players, seek to the position in the file previously 
        //occupied by the player, and overwrite the previous information
     }else{
        player_info.seekp((x[i].givePos()) * sizeof(temp), ios::beg);
        player_info.write(reinterpret_cast<char *>(&temp),sizeof(temp));
     }
 }   //close the player.txt file 
      player_info.close();
}
blackJack::~blackJack() {
}

/*disRule -> Used to display all the rules of the game given a player
 does not no how to player and prompts to hear them, simply a wall of text, 
 does not consist of anything significant, but made it cleaner to separate it
 and only call it if a player prompts the program to do so.*/
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



