/****
 * Write a program that, given an array A[] of n numbers
 * and another number x, determines whether or not there 
 * exist two elements in S whose sum is exactly x. 
 ****/
#include<bits/stdc++.h>
using namespace std;
// using sorting and two pointer method
// time complexity O(nlogn) if merge sort is used
// else O(n^2) if quick sort is used
void pairSum(int arr[],int n, int x){
    int l = 0;
    int r = n-1;
    sort(arr,arr+n);
    while (l<=r && (l<n && r>=0))
    {
        if(arr[l] + arr[r] == x) {
            cout<<arr[l]<<" "<<arr[r]<<endl;
            return;
        }
        if((arr[l] + arr[r])>x) r--;
        if((arr[l] + arr[r])<x) l++;
    }
    cout<<"No two such elements found";
}
// using hash maps
// Time complexity - O(n) Space Complexity - O(n)
void pairSum_2(int arr[],int n, int x){
    set<int>s;
    for(int i=0;i<n;i++){
        if(s.find(x - arr[i]) == s.end()){
            s.insert(arr[i]);
        }else{
            cout<<arr[i]<<" "<<x-arr[i]<<endl;
            return;
        }
    }
    cout<<"No such pair is found";
}
int main(){
    int A[] = {1, 4, 45, 6, 10, -8};
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);
    pairSum_2(A,arr_size,n);
    return 0;
}