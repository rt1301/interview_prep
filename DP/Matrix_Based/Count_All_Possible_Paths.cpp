/****
 * The problem is to count all the possible paths from top left to bottom 
 * right of a mXn matrix with the constraints that from each cell you can 
 * either move only to right or down
 ****/
#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int solve(int m, int n){
    if(m == 1 || n == 1){
        return 1;
    }
    if(dp[m][n] != -1) return dp[m][n];
    int r,d;
    if(dp[m][n-1] != -1){
        r = dp[m][n-1];
    }else{
        r = solve(m,n-1);
    }
    if(dp[m-1][n] != -1){
        d = dp[m-1][n];
    }else{
        d = solve(m-1,n);
    }
    return dp[m][n] = r+d;
}

int main(){
    int m,n;
    cin>>m>>n;
    memset(dp,-1,sizeof(dp));
    cout<<solve(m,n);
    return 0;
}