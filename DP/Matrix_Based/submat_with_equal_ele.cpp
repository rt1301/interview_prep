/****
 * Given a N x N matrix, determine the maximum K such that K x K is a 
 * submatrix with all equal elements i.e., all the elements in this submatrix must be same. 
 ****/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>mat){
    int n = mat.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            int val = mat[i][j];
            if(mat[i-1][j-1] == val && mat[i-1][j] == val && mat[i][j-1] == val){
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }else{
                dp[i][j] = max({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
        }
    }
    return dp[n-1][n-1];
}

int main()
{
    int n; cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<solve(v);
    return 0;
}