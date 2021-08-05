/****
 * Consider a n*n matrix. Suppose each cell in the matrix has a value assigned. 
 * We can go from each cell in row i to a diagonally higher cell in 
 * row i+1 only [i.e from cell(i, j) to cell(i+1, j-1) and cell(i+1, j+1) only]. 
 * Find the path from the top row to the bottom row following the 
 * aforementioned condition such that the maximum sum is obtained.
 ****/
#include<bits/stdc++.h>
using namespace std;
bool isValid(int x, int y, int n){
    if(x>=0 && x<n && y>=0 && y<n){
        return true;
    }
    return false;
}
int solve(vector<vector<int>>mat){
    int n = mat.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][0] = mat[i][0];
        dp[0][i] = mat[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            int l = 0,r=0;
            if(isValid(i-1,j+1,n)){
                l = dp[i-1][j+1];
            }
            if(isValid(i-1,j-1,n)){
                r = dp[i-1][j-1];
            }
            dp[i][j] = mat[i][j] + max(l,r);
        }
    }
    int res = INT_MIN;
    for(int i=0;i<n;i++){
        res = max(res,dp[n-1][i]);
    }
    return res;
}
int main(){
    vector<vector<int>>mat = {
        {5,6,1,7},
        {-2,10,8,-1},
        {3,-7,-9,11},
        {12,-4,2,6}
    };
    cout<<solve(mat);
    return 0;
}