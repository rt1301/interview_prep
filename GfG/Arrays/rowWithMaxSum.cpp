/****
 * Given a boolean 2D array, where each row is sorted.
 * Find the row with the maximum number of 1s. 
 ****/
#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
int binarySearch(int arr[],int low,int high){
    int l = low;
    int r = high;
    int m = 0;
    if (l<=r)
    {
        m = l + (r-l)/2;
        // check if the middle element is the first 1
        if((m == 0 || arr[m-1] == 0) && arr[m] == 1){
            return m;
        }
        // if ele is 0, check recursively the right side
        if(arr[m] == 0){
            return binarySearch(arr,m+1,r);
        }else{
            // if the ele is 1, check recursively for the first one
            // in the left side
            return binarySearch(arr,l,m-1);
        }
    }
    return -1;
}
int maxRow(int arr[R][C]){
    int sum = 0,max=-1;
    // Traverse for each row and count number of 1s
    // by finding the index of first 1
    for(int i=0;i<R;i++){
        int index = binarySearch(arr[i],0,C-1);
        if(index != -1 && C-index>max){
            max = C-index;
            sum = i;
        }
    }
    return sum;
}

int main(){
    int mat[R][C] = {{0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};

    cout << "Index of row with maximum 1s is " << maxRow(mat);

    return 0;
}