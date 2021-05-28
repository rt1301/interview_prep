/****
 * Given an array of integers which is initially increasing and then decreasing
 * find the maximum value in the array. 
 ****/
#include<bits/stdc++.h>
using namespace std;

int maxEle(int arr[],int n){
    int l = 0;
    int r = n-1;
    int m;
    while ((r-l)>1)
    {
        m = l + (r-l)/2;
        if(arr[m]>arr[m+1] && arr[m]>arr[m-1]) return arr[m];
        if(arr[m]<arr[m+1]){
            l = m +1;
        }else if(arr[m]<arr[m-1]){
            r = m;
        }
    }

    return max(arr[l],arr[r]);
    
}


int main(){
    int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum element is " << maxEle(arr,n);
    return 0;
}