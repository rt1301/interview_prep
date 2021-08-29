#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<bool>>mat, int r, int c,vector<vector<bool>>vis){
    int m = mat.size();
    int n = mat[0].size();
    return (r >= 0 && r < m && c >= 0 && c < n) && (mat[r][c] && !vis[r][c]);
}
void DFS(vector<vector<bool>>mat, int &count, vector<vector<bool>>&vis, int r, int c){
    vector<int> row = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> col = {-1, 0, 1, -1, 1, -1, 0, 1};
    vis[r][c] = 1;
    for(int i=0;i<8;i++){
        int dx = r + row[i];
        int dy = c + col[i];
        if(isSafe(mat,dx,dy,vis)){
            count++;
            DFS(mat,count,vis,dx,dy);
        }
    }
}

int largestRegion(vector<vector<bool>>mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<bool>>vis(m,vector<bool>(n,0));
    int res = INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1 && !vis[i][j]){
                int count = 1;
                DFS(mat,count,vis,i,j);
                res = max(res,count);
            }
        }
    }
    return res;
}

int main(){
    vector<vector<bool>> mat = { {0, 0, 1, 1, 0},
                                 {1, 0, 1, 1, 0},
                                 {0, 1, 0, 0, 0},
                                 {0, 0, 0, 0, 1}
    };
    cout<<largestRegion(mat);
    return 0;
}