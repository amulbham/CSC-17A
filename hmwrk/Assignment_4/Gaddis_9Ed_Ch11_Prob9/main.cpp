/*Author: Amul Bham
Purpose:Create a structure
to store information
about a speaker
Date : 10/9/2015*/


//System Libraries
#include <iostream>

using namespace std;
//Global Variables

//Function Prototypes

//User Libraries

//Execution Begins Here
int main()
{
    //Declare Variables
 struct speaker{
    string name;
    float number;
    string topic;
    float fee;

 }   ;
    speaker spk[10];
    bool term = true;
    do{
    int opt;
    cout<<"Menu:"<<endl;
    cout<<"1.) Enter Speaker Data\n 2.)Edit Speaker Data \n 3.)Display Speaker Data \n 4.) End Program "<<endl;
    cin>>opt;
    switch(opt){
    case 1:
        bool val;
        char cont;
    for(int i =0;i<10 || val;i++){
      cout<<"Speaker: "<<(i+1)<<endl;
      cout<<"Speaker Name: "<<endl;
      cin>>spk[i].name;
      cout<<"Telephone Number: "<<endl;
      cin>>spk[i].number;
        cout<<"Topic: "<<endl;
        cin>>spk[i].topic;
        cout<<"Fee: "<<endl;
        cin>>spk[i].fee;
        cout<<"Continue? y/n"<<endl;
        cin>>cont;
        if (cont == 'n' || cont == 'N'){val = false;}
    }
    case 2:
    int choice;
    cout<<"Which User would you like to edit?"<<endl;
    cin>>choice;
      cout<<"Speaker Name: "<<endl;
      cin>>spk[choice].name;
      cout<<"Telephone Number: "<<endl;
      cin>>spk[choice].number;
        cout<<"Topic: "<<endl;
        cin>>spk[choice].topic;
        cout<<"Fee: "<<endl;
        cin>>spk[choice].fee;
     case 3:
        for(int i =0;i<10;i++){
      cout<<"Speaker Name: "<<spk[i].name<<endl;
      cout<<"Telephone Number: "<<spk[i].number<<endl;
        cout<<"Topic: "<<spk[i].topic<<endl;
        cout<<"Fee: "<<spk[i].fee<<endl;
    }
     case 4:
        term = false;
     case 5:
        term = false;

    }
    }while(term);

    //Exit stage right!
    return 0;
}
