/****
 * Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] 
 * such that sorting this subarray makes the whole array sorted. 
 ****/
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    int s=0,e=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            s = i;
            break;
        }
    }

    for(int i=n-1;i>0;i--){
        if(arr[i]<arr[i-1]){
            e = i;
            break;
        }
    }
    if (s == n - 1)
    {
        cout << "The complete array is sorted";
        return;
    }
    int min=arr[s],max=arr[s];
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    for(int i=0;i<=s-1;i++){
        if(arr[i]>min){
            s = i;
            break;
        }
    }

    for(int i=n-1;i>=e+1;i--){
        if(arr[i]<max){
            e = i;
            break;
        }
    }
    cout<<s<<" "<<e<<endl;
}
int main(){
    int arr[] = {10, 12, 20, 30, 25,
                 40, 32, 31, 35, 50, 60};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    solve(arr,arr_size);
    return 0;
}