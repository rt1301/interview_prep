/****
 * Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
 ****/
#include<bits/stdc++.h>
using namespace std;
int maxAns = INT_MIN;
int lcsRecursive(string x, string y, int n, int m, int ans){
    if(m == 0 || n == 0){
        return maxAns = max(maxAns,ans);
    }
    if(x[n-1] == y[m-1]){
        lcsRecursive(x,y,n-1,m-1,ans+1);
    }else{
        lcsRecursive(x,y,n-1,m,0);
        lcsRecursive(x,y,n,m-1,0);
    }
    return maxAns;
}
int lcs(string x, string y, int n, int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }
        }
    }
    int maxAns = INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            maxAns = max(maxAns, dp[i][j]);
        }
    }
    return maxAns;
}
int main(){
    string x,y;
    cin>>x>>y;
    int n = x.length();
    int m = y.length();
    int ans = -1;
    cout<<lcs(x,y,n,m);
    cout<<"\nRecursive Solution\n"<<lcsRecursive(x,y,n,m,ans);
    return 0;
}