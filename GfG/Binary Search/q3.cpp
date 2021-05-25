/****
 * Given a sorted array with possible duplicate elements.
 * Find number of occurrences of input ‘key’ in log N time.
 ****/
#include<bits/stdc++.h>
using namespace std;
int rightPos(int arr[],int n,int key){
    int l = 0;
    int r = n;
    int m;
    while((r-l)>1){
        m = l + (r-l)/2;
        if(arr[m]<=key){
            l = m;
        }else{
            r = m;
        }
    }
    return l;
}
int leftPos(int arr[],int n,int key){
    int l = -1;
    int r = n-1;
    int m;
    while((r-l)>1){
        m = l + (r-l)/2;
        if(arr[m]>=key){
            r = m;
        }else{
            l = m;
        }
    }
    return r;
}
int countOccurances(int arr[],int n, int key){
    int count = 0;
    int left = leftPos(arr,n,key);
    int right = rightPos(arr,n,key);
    if(arr[left] == key && arr[right] == key) return right-left+1;
    return 0;
}
int main(){
    int a[7] = {1, 1, 2, 2, 2, 2, 3};
    int ans = countOccurances(a,7,2);
    cout<<ans;
    return 0;
}