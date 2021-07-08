/****
 * Given a rod of length n inches and an array of prices that includes 
 * prices of all pieces of size smaller than n. Determine the maximum 
 * value obtainable by cutting up the rod and selling the pieces. 
 * For example, if the length of the rod is 8 and the values of different 
 * pieces are given as the following, then the maximum 
 * obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 
 ****/
// This is a exact variation of Unbounded Knapsack Problem
#include<bits/stdc++.h>
using namespace std;

int rodCutting(int len[], int price[], int N){
    int t[N+1][N+1];
    for(int i=0;i<=N;i++){
        t[i][0] = 0;
        t[0][i] = 0;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(len[i-1]<=j){
                t[i][j] = max(price[i-1] + t[i][j-len[i-1]], t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[N][N];
}

int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int len[size];
    for(int i=0;i<size;i++){
        len[i] = i+1;
    }
    cout<<"Maximum Obtainable Value is "<<rodCutting(len,arr, size);
    return 0;
}