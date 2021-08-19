/****
 * Given two strings, find the number of times the second string occurs 
 * in the first string, whether continuous or discontinuous.
 ****/
#include<bits/stdc++.h>
using namespace std;
int numSubseq(string a, string b, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    for(int i=0;i<=m;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m = s1.length();
    int n = s2.length();
    cout<<numSubseq(s1,s2,m,n);
    return 0;
}