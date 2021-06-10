/****
 * Given an integer representing a given amount of change, 
 * write a function to compute the total number of coins required to make 
 * that amount of change. You can assume that there is always a 1¢ coin.
 ****/
#include<bits/stdc++.h>
using namespace std;
// Unoptimized Solution - O(c^n)
// int makeChange(int coins[],int n,int c){
//     if(c == 0) return 0;
//     int minCoins = INT_MAX;
//     // try removing each coin from the total 
//     // and check how many more coins are required
//     for(int coin = 0;coin<n;coin++){
//         // skip a coin if it's value is greater than
//         // the total amount remaining
//         if(c-coins[coin]>=0){
//             int currMinCoins = makeChange(coins,n,c-coins[coin]);
//             if(currMinCoins<minCoins){
//                 minCoins = currMinCoins;
//             }
//         }
//     }
//     return minCoins+1;
// }

// Optimized DP Soln
int makeChange(int coins[],int n,int sum){
    // create the DP array
    int dp[sum+1][n+1];
    // initialize the base cases
    // when sum == 0, then there will be only
    // 1 possible case,i.e, not selecting any coin
    for(int i=0;i<=n;i++){
        dp[0][i] = 1;
    }
    // when n == 0 and sum>0 then there will be no
    // possible cases
    for(int i=1;i<=sum;i++){
        dp[i][0] = 0;
    }
    // fill the DP table
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            // Case 1: When we are excluding the last coin
            dp[i][j] = dp[i][j-1];
            // Case 2: When we are including the last coin
            if(coins[j-1]<=i) // coin is less than reqd sum
            {
                dp[i][j]+=dp[i-coins[j-1]][j]; // length of array will be n
                                               // sum= sum - coins[n-1]
            }
        }
    }
    return dp[sum][n];
}
int main(){
    int coins[3] = {1,2,3};
    cout << makeChange(coins, 3, 4);
    int coins_2[4] = {2,5,3,6};
    cout<<endl<<makeChange(coins_2,4,10);
    return 0;
}