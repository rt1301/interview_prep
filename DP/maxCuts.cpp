/****
 * You are given a rod of length n, and three possible smaller lengths
 * a, b and c. Find the max no of cuts reqd so that all individual smaller 
 * rods are of the lengths a, b or c
 ****/
#include<bits/stdc++.h>
using namespace std;

int maxCut(int n, int a, int b, int c){
    int dp[n+1];
    dp[0] = 0; // initialize 0 length rod
    for(int i=1;i<=n;i++){
        dp[i] = -1;
        if(i-a>=0) dp[i] = max(dp[i],dp[i-a]); //smaller rod of length a
        if(i-b>=0) dp[i] = max(dp[i],dp[i-b]); // smaller rod of length b
        if(i-c>=0) dp[i] = max(dp[i],dp[i-c]); // smaller rod of length c

        if(dp[i] != -1){
            dp[i]++;
        }
    }
    return dp[n];
}

int main(){
    cout<<maxCut(5,1,2,3)<<endl<<maxCut(23,12,11,13)<<endl<<maxCut(3,2,4,2);
    return 0;
}