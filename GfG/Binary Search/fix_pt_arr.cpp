/****
 * Given an array of n distinct integers sorted in ascending order,
 * write a function that returns a Fixed Point in the array, 
 * if there is any Fixed Point present in array, else returns -1.
 * Fixed Point in an array is an index i 
 * such that arr[i] is equal to i. Note that integers in array can be negative.
 ****/
#include<bits/stdc++.h>
using namespace std;
int fixPointLinear(int arr[],int n){
    // Using Linear Search
    for(int i=0;i<n;i++){
        if(arr[i] == i) return i;
    }
    return -1;
}

int fixPointBinary(int arr[],int n){
    // Binary Search
    int l =0;
    int r = n-1;
    int m;
    while(l<=r){
        m = l + (r-l)/2;
        if(arr[m] == m) return m;
        if(arr[m]>m){
            r = m-1; //if index is smaller then fix pt lies on the left side of m
        }else{
            l = m+1; //if index is greater then fix pt lies on the right side of m
        }
    }
    return -1;
}

int main(){
    int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Fixed Pt using Linear Search\t"<<fixPointLinear(arr,n);
    cout<<"\nFixed Pt using Binary Search\t"<<fixPointBinary(arr,n);
    return 0;
}