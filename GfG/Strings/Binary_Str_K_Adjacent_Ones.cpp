/****
 * Given two integers n and k, count the number of binary strings of 
 * length n with k as number of times adjacent 1’s appear.
 ****/
#include<bits/stdc++.h>
using namespace std;
int solve(int n, int k){
    // n length, k adjacent ones and ending with either 0 or 1
    int dp[n+1][k+1][2];

    memset(dp, 0, sizeof(dp));
    // if n = 1 and k = 0
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j][0];

            if (j - 1 >= 0)
                dp[i][j][1] += dp[i - 1][j - 1][1];
        }
    }

    return dp[n][k][0] + dp[n][k][1];
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k);
    return 0;
}