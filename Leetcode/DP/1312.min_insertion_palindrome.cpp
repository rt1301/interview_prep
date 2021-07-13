#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    int minInsertions(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        int m = s.length();
        int ans = m - lcs(s,t,m,m);
        return ans;
    }
};