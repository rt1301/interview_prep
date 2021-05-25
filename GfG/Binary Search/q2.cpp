/****
 * Given an array of N distinct integers, find floor value of input ‘key’.
 * Say, A = {-1, 2, 3, 5, 6, 8, 9, 10} and key = 7, we should return 6 as outcome.
 ****/
#include<bits/stdc++.h>
using namespace std;

int findFloor(int arr[],int n,int key){
    int l = 0;
    int r = n-1;
    int m;
    while((r-l)>1 && arr[l]<=key){
        m = l + (r-l)/2;
        if(arr[m] <=key){
            l = m;
        }else{
            r = m;
        }
    }
    return arr[l];
}

int main(){
    int a[8] = {-1, 2, 3, 5, 6, 8, 9, 10};
    int ans = findFloor(a,8,7);
    cout<<ans;
    return 0;
}