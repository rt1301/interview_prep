/****
 * The longest Zig-Zag subsequence problem is to find length of the 
 * longest subsequence of given sequence such that all elements of this are alternating. 
 ****/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int n){
    int dp[n][2];
    for(int i=0;i<n;i++){
        dp[i][0] = dp[i][1] = 1;
    }
    int res = INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[j][1]+1>dp[i][0]){
                dp[i][0] = dp[j][1] + 1;
            }
            if(arr[i]<arr[j] && dp[j][0]+1>dp[i][1]){
                dp[i][1] = dp[j][0]+1;
            }
        }
        res = max(res,max(dp[i][0],dp[i][1]));
    }
    return res;
}

int main(){
    vector<int>arr = {10,22,9,33,49,50,31,60};
    // vector<int>arr = {1,5,4};
    int n = arr.size();
    cout<<solve(arr,n);
    return 0;
}