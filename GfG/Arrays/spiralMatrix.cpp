/****
 * Given a 2D array, print it in spiral form. See the following example.
 * Input:   1    2   3   4
            5    6   7   8
            9   10  11  12
            13  14  15  16
    Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
 ****/
#include<bits/stdc++.h>
using namespace std;
void printSpiralMatrix(vector<vector<int>>mat){
    int n = mat.size();
    // four pointers for four directions
    int left=0,right=n-1,top=0,bottom=n-1;
    // to denote the four directions
    // left->right = 0
    // top->bottom = 1
    // right->left = 2
    // bottom->top = 3
    int dir = 0;
    while (left<=right && top<=bottom)
    {
        if(dir == 0){
            // move left to right
            for(int i=left;i<=right;i++){
                cout<<mat[top][i]<<" ";
            }
            top++;
        }else if(dir == 1){
            // move top to bottom
            for(int i=top;i<=bottom;i++){
                cout<<mat[i][right]<<" ";
            }
            right--;
        }else if(dir == 2){
            // move right to left
            for(int i=right;i>=left;i--){
                cout<<mat[bottom][i]<<" ";
            }
            bottom--;
        }else if(dir == 3){
            // move bottom to top
            for(int i=bottom;i>=top;i--){
                cout<<mat[i][left]<<" ";
            }
            left++;
        }
        dir = (dir+1)%4; // after every four rev restore the direction order
    }
    
}

int main(){
    vector<vector<int>> a{{1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16}};
    printSpiralMatrix(a);
    return 0;
}