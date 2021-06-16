/****
 * Write an algorithm such that if an element in an 
 * M*N matrix is 0, its entire row and column are set to 0
 ****/
#include<bits/stdc++.h>
using namespace std;
void zeroMatrix(int mat[4][4]){
    vector<pair<int,int>>v;
    int N = 4;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mat[i][j] == 0){
                v.push_back(make_pair(i,j));
            }
        }
    }
    for(int k=0;k<v.size();k++){
        cout<<v[k].first<<" "<<v[k].second<<endl;
        for(int i=0;i<N;i++){
            mat[v[k].first][i] = 0;
        }
        for(int i=0;i<N;i++){
            mat[i][v[k].second] = 0;
        }
    }
}
void displayMatrix(int mat[4][4])
{
    int N = 4;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";

        cout << endl;
    }
    printf("\n");
}
int main(){
    int mat[4][4] = {
        {1,0,1,1},
        {2,3,0,4},
        {5,6,7,8},
        {9,10,11,0}
    };
    cout<<"Original Matrix\n";
    displayMatrix(mat);
    zeroMatrix(mat);
    cout<<"Updated Matrix\n";
    displayMatrix(mat);
    return 0;
}