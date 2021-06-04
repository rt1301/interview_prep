/****
 * Given an n x n matrix and a number x, find the position of x in the matrix
 * if it is present in it. Otherwise, print “Not Found”. 
 * In the given matrix, every row and column is sorted in increasing order.
 * The designed algorithm should have linear time complexity. 
 ****/
#include<bits/stdc++.h>
using namespace std;
int search(int arr[4][4],int n,int x){
    if(n==0) return -1;
    if(x>arr[n-1][n-1] || x<arr[0][0]) return -1;
    int i = 0; //first row
    int j = n-1; // last column
    while (i<n && j>=0)
    {
        if(arr[i][j] == x){
            cout<<"Element Found at "<<i<<", "<<j<<endl;
            return 1;
        }
        if(arr[i][j] < x){
            i++;
        }else{
            j--;
        }
    }
    cout<<"Element Not found\n";
    return -1;
}

int main(){
    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    search(mat, 4, 29);

    return 0;
    return 0;
}