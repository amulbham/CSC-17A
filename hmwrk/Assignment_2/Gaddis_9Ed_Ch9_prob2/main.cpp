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
    srand(time(NULL));   //Random Number seed to initialize array
    int SIZE = (rand()%30)+1; //size of the array will be random
    int arr[SIZE];      //array where list will be stored
    float med;          //variable to store median value
    
    //Initialize array with random values 1-100
    for (int i = 0; i<SIZE;i++){
        arr[i] = (rand()%100)+1;
        cout<<arr[i]<<endl;
    }
    cout<<endl<<endl;
    //Pass to the get median function to determine median
    med = getMed(arr,SIZE);
    
    //Output the median 
    cout<<"The array had "<<SIZE<<" numbers"<<endl;
    cout<<"The median of the list is "<<med<<endl;
    
    //Exit stage right!
    return 0;
}

float getMed(int *arr,int size){
    //Declare Variables
    float med; //Median of the array
    vector<int> temp; //create a temp vector to store the array
    temp.assign(arr, arr + size); //puts all the arr data into the vector
    
    //Sort the vector in ascending order using sort function
    sort(temp.begin(),temp.end()); 
    
    //Output the new sorted list to verify sort
    for(int i =0;i<size;i++){
        cout<<temp[i]<<endl;
        }
    
    //Determine if median is even or odd - then determine median number
     if (size  % 2 == 0){ //determines if even
      med = (temp[size / 2 - 1] + temp[size / 2]) / 2;
    }else { //Odd number of values = size / 2;
      med = temp[size / 2];
    }
    
    //Return the median back to the main function
    return med; 
}