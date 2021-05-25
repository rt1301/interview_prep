/****
 * Given a sorted array of distinct elements, and the array is rotated at an unknown position.
 * Find minimum element in the array.
 ****/
#include<bits/stdc++.h>
using namespace std;

int findMin(int arr[],int n){
    int l = 0;
    int r = n-1;
    int m;
    if(arr[l]<=arr[r]){
        return arr[l];
    }
    while(l<=r){
        // Termination condition (l will eventually fall on r, and r always
        // point minimum possible value)
        if(l == r) return arr[l];
        m = l + (r - l) / 2; // 'm' can fall in first pulse,
                             // second pulse or exactly in the middle
        if(arr[m]<arr[r]){
            // min can't be in the range
            // (m < i <= r), we can exclude A[m+1 ... r]
            r = m;
        }else{
            // min must be in the range (m < i <= r),
            // we must search in A[m+1 ... r]
            l = m+1;
        }
    }
    return -1;
}
int main(){
    int arr[10] = {6,7,8,9,10,1,2,3,4,5};
    int min = findMin(arr,10);
    cout<<min;
    return 0;
}