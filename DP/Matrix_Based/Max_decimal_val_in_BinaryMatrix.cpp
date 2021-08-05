/****
 * Given binary square matrix [n*n]. Find maximum integer value in a path 
 * from top left to bottom right. We compute integer value using bits of traversed path. 
 * We start at index [0,0] and end at index [n-1][n-1]. from index [i, j], 
 * we can move [i, j+1] or [i+1, j]. 
 ****/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>mat){
    int n = mat.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = mat[0][0];
    for(int i=1;i<n;i++){
        dp[0][i] = mat[0][i] == 1?(dp[0][i-1]+pow(2,i)):dp[0][i-1];
        dp[i][0] = mat[i][0] == 1?(dp[i-1][0] + pow(2,i)):dp[i-1][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = mat[i][j] * pow(2, i + j) + max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n-1][n-1];
}
int main(){
    vector<vector<int>>v = {
        {1,1,0,1},
        {0,1,1,0},
        {1,0,0,1},
        {1,0,1,1}
    };
    cout<<solve(v);
    return 0;
}