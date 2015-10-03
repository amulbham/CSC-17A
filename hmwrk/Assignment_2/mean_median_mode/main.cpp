/* 
 * File:   main.cpp
 * Author: Amul Bham
 * Purpose: Calculate the Mean,
 * Median, mode, etc. of
 * a repeating array utilizing
 * dynamic arrays
 * Created on October 2, 2015, 5:28 PM
 */
//System Libraries
#include <iostream> //used to take input and output results
#include <ctime>    //used for the random number seed for array
#include <algorithm>//used for sort functions    
#include <vector>   //used to store array values for sort
#include <iomanip>  //used to format the mean into for two places after decimal

using namespace std;
//Global Constants

//User Libraries

//Function Prototypes
float mean(int [],int);
float median(int [],int);
int gtmode(int [],int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    int* arr = NULL; //to store the values to be sorted, dynamically allocated
    int NUM;       //will hold the number of values stored in our array
    srand (time(NULL)); //random number seed    
    float mn;       //mean of the number set
    float med;      //median of the number set
    int freq;       //frequency of the mode
    
    //Initialize the size of the array
    cout<<"Enter an integer to indicate how large the array should be"<<endl;
    cin>>NUM;
    
    //allocate NUM and save the pointer as a normal variable p
    arr = new int[NUM];  
    
    
    //Initialize the array with random numbers between 1-30
    cout<<"Your random array is ..."<<endl;
    for (int i =0;i<NUM;i++){
        arr[i] = rand()%30 +1; 
        cout<<arr[i]<<", ";
    }
    //Calculate the mean, median, and mode 
        /*Mean*/
            mn = mean(arr,NUM); 
        /*Median*/    
            med = median(arr,NUM);
        /*frequency*/  
           freq = gtmode(arr,NUM);
          
    //Output the results
            cout<<"The frequency of the mode is "<<freq<<endl;
            cout<<"The median of the array is "<<med<<endl;
            cout<<fixed<<showpoint<<setprecision(2);
            cout<<"The mean of the array is "<<mn<<endl;
            
    //free the memory allocated to the array
            delete [] arr;
    //Exit the stage right !
    return 0;
}

float mean(int arr[],int num){
    //Declare Variables
    float mean; //sum of array values
    
    //calculate mean - add all values /2
        for(int i = 0; i<num;i++){
            mean += arr[i];
    }
    //divide by the total number of values to obtain mean
    mean /= num;
    //return the mean back to the main function 
    return mean;
}


float median(int arr[],int num){
    //Declare Variables
    float med; //Median of the array
    vector<int> temp; //create a temp vector to store the array
    
    /*Put the data from array into a vector, this allows us to use the sort
    function to easily sort the list in ascending order*/
    temp.assign(arr, arr + num); 
    sort(temp.begin(),temp.end()); //must be sorted for median 
    
    cout<<endl;
    //Determine if median is even or odd - then determine median number
    if (num  % 2 == 0){ //determines if even
      med = (temp[num / 2 - 1] + temp[num / 2]) / 2;
    }else{ //Odd number of values = size / 2;
      med = temp[num / 2];
    }
    //Return the median back to the main function
    return med; 
}


int gtmode(int arr[],int num){
    //Declare Variables
    vector<int> temp; //create a temp vector to store the array
    
    /*Put the data from array into a vector, this allows us to use the sort
    function to easily sort the list in ascending order*/
    temp.assign(arr, arr + num); 
    sort(temp.begin(),temp.end()); //must be sorted for median 
  
    //Use a loop to compare values of array
    int number = temp[0]; //compare number
    int m = number;       //the mode of the list
    int count = 1;        //counter to track the frequency
    int freq = 1;           //frequency of the mode  

    for (int i=1; i<num; i++){
      if (temp[i] == number){ //if the numbers are the same
         count++; //add 1 to the frequency
      }else{
            if (count > freq) //if the new number has a greater freq.
            {
                  freq = count;
                  m = number;
            }
           count = 1;       //reset the count for the next number
           number = temp[i]; //set the number = to the old one
  }
}       //Output the mode/modes of the set
        cout<<"The mode(s) of the set is "<<m<<endl;
        
        //Return the frequency of the mode(s)
        return freq;

}