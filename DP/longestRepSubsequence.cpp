/****
 * Given a string, print the longest repeating subsequence such that 
 * the two subsequence don’t have same string character at same position, 
 * i.e., any i’th character in the two subsequences shouldn’t have the 
 * same index in the original string.
 ****/
#include<bits/stdc++.h>
using namespace std;

int lrs(string x, string y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                break;
            }
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1] && i!=j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main(){
    string x;
    cin>>x;
    string y = x;
    int m = x.length();
    cout<<"Longest Repeating Subsequence is "<<lrs(x,y,m,m);
    return 0;
}