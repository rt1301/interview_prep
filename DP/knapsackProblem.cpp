/****
 * Given an value array, a weight array and total Weight capacity
 * Pick 0 or more items from knapsack such that total weight of 
 * given items <= W and value is maximized
 ****/
#include<bits/stdc++.h>
using namespace std;

int knapsack(int W,int wt[],int val[],int n){
    int dp[n+1][W+1];
    // dp[i] = max values that can be collected with first i 
    // items and knapsack weight capacity

    // Base Conditions
    for(int i=0;i<=W;i++) dp[0][i] = 0;
    for(int j=0;j<=n;j++) dp[j][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            // checking if the weight of the selected item
            // is less than or greater than the current knapsack
            // capacity
            if(wt[i-1]>j){ // greater
                dp[i][j] = dp[i-1][j]; // store the previous item's weight
            }else{
                // Two Cases: 
                // 1. Include the last item and reduce the weight from knapsack capacity
                // 2. Exclude the last item
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
        }
    }
    return dp[n][W];
}

int main(){
    int v[] = {10,40,30,50};
    int wt[] = {5,4,6,3};
    int n = sizeof(v)/sizeof(v[0]);
    int W = 10;
    cout<<knapsack(W,wt,v,n);
    return 0;
}