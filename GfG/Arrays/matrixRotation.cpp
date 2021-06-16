/****
 * Rotate a matrix of size N*N by 90 degrees
 ****/
#include<bits/stdc++.h>
using namespace std;
void rotatedMatrix(int m[4][4]){
    int N = 4;
    // consider all the squares or cycles in a matrix
    for(int x=0;x<N/2;x++){
        // select individuals in a group
        // 4 elements at a time
        for(int y=x;y<N-x-1;y++){
            // store the current cell in temp variable
            int temp = m[x][y];
            // right to top
            m[x][y] = m[y][N-1-x];
            // bottom to right
            m[y][N-1-x] = m[N-1-x][N-1-y];
            // left to bottom
            m[N-1-x][N-1-y] = m[N-1-y][x];
            // top to left
            m[N-1-y][x] = temp;
        }
    }
}

void displayMatrix(int mat[4][4])
{
    int N = 4;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j]<<" ";
        
        cout<<endl;
    }
    printf("\n");
}
int main(){
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    rotatedMatrix(mat);

    // Print rotated matrix
    displayMatrix(mat);

    return 0;
}