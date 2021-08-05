#include<bits/stdc++.h>
using namespace std;

void traversal(vector<vector<int>>&mat){
    int r = mat.size();
    int c = mat[0].size();
    int step = 1;
    for(int line=1;line<=(r+c-1);line++){
        int start_col = max(0,line-r);

        int count = min({line, c-start_col, r});

        for(int j=0;j<count;j++){
            mat[min(r,line)-j-1][start_col+j] = step;
            cout<<setw(5)<<mat[min(r,line)-j-1][start_col+j];
            step++;
        }
        cout<<endl;
    }
}
void print(vector<vector<int>>mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>>mat={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    traversal(mat);
    print(mat);
    return 0;
}