/****
 * Given a number n
 * Count the total number of BSTs possible with n nodes
 ****/
#include<bits/stdc++.h>
using namespace std;

int countBST(int n){
    int dp[n+1]; // dp table
    // dp[i] = Result of i keys
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        dp[i] = 0;
        // filling the dp table according to the relation
        // res(n) = Sum(i=0 to i=n-1)(res(i)*res(n-i-1))
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n = 5;
    cout<<countBST(n);
    return 0;
}