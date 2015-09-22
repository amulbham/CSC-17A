/* 
 * File:   main.cpp
 * Author: Amul Bham
 * Purpose: Create a function 
 * that determines the median of 
 * an array returned as a float
 *
 * Created on September 22, 2015, 1:02 PM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;
//Global Constants

//Function Prototypes
float getMed(int *,int); //get the median of array - use pointer notation  

//User Libraries


//Execution begins here 
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE = 20; //Size of the array
    int arr[SIZE];      //array where list will be stored
    srand(time(NULL));//Random Number seed to initialize array
    float med;          //variable to store median value
    
    //Initialize array with random values 1-100
    for (int i = 0; i<SIZE;i++){
        arr[i] = (rand()%100)+1;
        cout<<arr[i]<<endl;
    }
    
    for (int i = 0; i<SIZE;i++){
        arr[i] = (rand()%100)+1;
        cout<<arr[i]<<endl;
    }
    
    //Pass to the get median function to determine median
    med = getMed(arr,SIZE);
    
    //Output the median 
    
    
    //Exit stage right!
    return 0;
}

float getMed(int *arr,int SIZE){
    //Declare Variables
    int med; //Median of the array
    vector<int> temp(arr,arr+20); //create a temp vector to store the array
    
    //Sort the vector in ascending order
    sort(temp.begin(),temp.end());
    
    
    
    
    //Determine if the median is even or odd
    
    
    //Return the median back to the main function
    return med; 
}