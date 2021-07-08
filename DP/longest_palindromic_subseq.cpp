/****
 * Given a sequence, find the length of the longest palindromic subsequence in it.
 ****/
#include<bits/stdc++.h>
using namespace std;
int lcs(string x, string y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else{
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[m][n];
}

int main(){
    string x;
    cin>>x;
    int m = x.length();
    string y = x;
    reverse(x.begin(),x.end());
    int ans = lcs(x,y,m,m);
    cout<<"Longest Palindromic Subsequence is "<<ans;
    /****
     * Minimum number of deletions to make a string palindrome 
     * Given a string of size ‘n’. The task is to remove or delete minimum 
     * number of characters from the string so that the resultant 
     * string is palindrome.
     ****/
    int minDeletions = m-ans;
    cout<<"\nMinimum Deletions to make "<<x<<" Palindrome is "<<minDeletions;
    return 0;
}