/****
 * Given an array of coins, and a value
 * Find the minimum number of coins equal to the given value
 ****/
#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[],int n,int val){
    int dp[val+1]; //creating a dp arr of size val+1
    dp[0] = 0; // initialize dp[0] = 0
    for(int i=1;i<=val;i++){
        dp[i] = INT_MAX;
        for(int j=0;j<n;j++){ //comparing dp[i] with the coins available
            if(coins[j]<=i){ 
                dp[i] = min(dp[i],dp[i-coins[j]]+1); //min value between existing dp[i] and
                                                     // value at i-coins[i] index in the dp array
            }
        }
    }
    if(dp[val] != INT_MAX){
        return dp[val];
    }else{
        return -1;
    }
    
}

int main(){
    int arr[] = {25,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = 30;
    cout<<minCoins(arr,n,val);
    return 0;
}