/****
 * Give an array of n elements.
 * arr[i] = num of jumps available from that particular element
 * Find the minimum number of jumps required to reach the last element from the first one
 ****/
#include<bits/stdc++.h>
using namespace std;
int minJumps(int arr[],int n){
    int dp[n]; // dp array of size n
    dp[0] = 0; // first element doesn't require any jumps
    for(int i=1;i<n;i++){
        dp[i] = INT_MAX; // dp[i] = min jumps require to reach index i from 0
        for(int j=0;j<i;j++){
            if(arr[j] + j >= i){
                if(dp[j] != INT_MAX){
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
    }
    return dp[n-1];
}

int main(){
    int arr[] = {3,4,2,1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<minJumps(arr,size);
    return 0;
}