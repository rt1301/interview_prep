/****
 * Given a matrix of size n x n, find the sum of the Zigzag sequence with the 
 * largest sum. A zigzag sequence starts from the top and ends at the bottom. 
 * Two consecutive elements of sequence cannot belong to the same column. 
 ****/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int dp[MAX][MAX];
int helper(vector<vector<int>>mat,int i, int j){
    int n = mat.size();
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == n-1){
        return dp[i][j] = mat[i][j];
    }
    int zzs = 0;
    for(int k=0;k<n;k++){
        if(k!=j){
            zzs = max(zzs, helper(mat,i+1,k));
        }
    }
    return dp[i][j] = (zzs + mat[i][j]);
}
int solve(vector<vector<int>>mat,int m, int n){
    int mx = 0;
    for(int i=0;i<n;i++){
        mx = max(mx,helper(mat,0,i));
    }
    return mx;
}
int main(){
    int m,n;
    cin>>m>>n;
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>mat(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<solve(mat,m,n);
    return 0;
}