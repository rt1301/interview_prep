/****
 * Given a matrix of integers where every element represents weight of the cell. 
 * Find the path having the maximum weight in matrix [N X N].
 * PS - https://www.geeksforgeeks.org/maximum-weight-path-ending-element-last-row-matrix/
 ****/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>mat){
    int n = mat.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = mat[0][0];
    for(int i=1;i<n;i++){
        dp[i][0] = mat[i][0] + dp[i-1][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n&&j<i+1;j++){
            dp[i][j] = mat[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
        }
    }
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mx = max(mx,dp[n-1][i]);
    }
    return mx;
}
int main(){
    vector<vector<int>>mat = {
        {4,2,3,4,1},
        {2,9,1,10,5},
        {15,1,3,0,20},
        {16,92,41,44,1},
        {8,142,6,4,8}
    };
    cout<<solve(mat);
    return 0;
}