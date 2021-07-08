// Print Longest Common Subsequence of two given strings
#include<bits/stdc++.h>
using namespace std;

string lcs(string x, string y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = m, j = n;
    string ans;
    while (i>0 && j>0)
    {
        if(x[i-1] == y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string x,y;
    cin>>x>>y;
    int m = x.length();
    int n = y.length();
    cout<<"LCS is "<<lcs(x,y,m,n);
    return 0;
}