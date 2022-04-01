/****
 * Given a sorted array of numbers, find if a given number key is present in the array. 
 * Though we know that the array is sorted, we don’t know if it’s 
 * sorted in ascending or descending order.
 ****/
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>arr, int x){
    int n = arr.size();
    int l = 0;
    int r = n-1;
    int m = 0;
    bool isAsc = false;
    if(arr[0]>arr[n-1]){
        isAsc = false;
    }else{
        isAsc = true;
    }
    while(l<=r){
        m = l + (r-l)/2;
        if(arr[m] == x){
            return m;
        }
        if(arr[m]>x){
            if(isAsc){
                r = m-1;
            }else{
                l = m+1;
            }
        }else{
            if(isAsc){
                l = m+1;
            }else{
                r = m-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int>v1 = {1,2,3,4,5,6,7,8,9};
    vector<int>v2 = {20,17,15,14,13,12,10,9,8,4};
    int x1 = 7;
    int x2 = 14;
    int i1 = binarySearch(v1,x1);
    int i2 = binarySearch(v2,x2);
    cout<<i1<<endl<<i2;
    return 0;
}