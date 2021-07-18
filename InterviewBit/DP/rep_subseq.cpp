#include<bits/stdc++.h>
using namespace std;
int lcs(string s, int m){
    int dp[m+1][m+1];
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if((s[i-1] == s[j-1]) && (i != j)){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][m];
}
int anytwo(string A) {
    int m = A.length();
    int ans = lcs(A,m);
    if(ans>1){
        return 1;
    }else{
        return 0;
    }
}
