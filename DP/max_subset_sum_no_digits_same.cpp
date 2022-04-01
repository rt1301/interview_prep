/****
 * Given an array of N elements. Find the subset of elements 
 * which has maximum sum such that no two elements in the subset 
 * has common digit present in them.
 ****/
#include<bits/stdc++.h>
using namespace std;
int dp[1024];
int get_binary(int u){
    int ans = 0;
    while(u != 0){
        int rem = u%10;
        ans |= (1<<rem);
        u/=10;
    }
    return ans;
}
int recur(int u,vector<int>arr){
    if(u == 0){
        return 0;
    }
    if(dp[u] != -1){
        return dp[u];
    }
    for(int i=0;i<arr.size();i++){
        int mask = get_binary(arr[i]);

        if((mask | u) == u){
            dp[u] = max(max(0,dp[u^mask])+arr[i],dp[u]);
        }
    }

    return dp[u];
}

int solve(vector<int>arr){
    int n = arr.size();
    memset(dp,-1,sizeof(dp));

    int ans = 0;
    for(int i=0;i<(1<<10);i++){
        ans = max(ans,recur(i,arr));
    }

    return ans;
}

int main(){
    vector<int>arr = {22, 132, 4, 45, 12, 223};
    int ans = solve(arr);
    cout<<ans<<endl;
    return 0;
}