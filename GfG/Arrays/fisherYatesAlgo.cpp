/****
 * Shuffle a given array using Fisher–Yates shuffle Algorithm
 * Given an array, write a program to generate a random permutation of array elements.
 * This question is also asked as “shuffle a deck of cards” or “randomize a given array”
 * Here shuffle means that every permutation of array element should equally likely. 
 ****/
#include<bits/stdc++.h>
using namespace std;

void shuffleArr(int arr[],int n){
    // Use a different seed value each time
    // so that no element is selected twice
    // in the randomize process
    srand(time(NULL));

    for(int i=n-1;i>=0;i--){
        int j = rand()%(i+1); //pick a random number from 0 to i
        swap(arr[i],arr[j]);
    }
}
void printArr(int arr[],int n){
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    shuffleArr(arr,n);
    printArr(arr,n);
    return 0;
}