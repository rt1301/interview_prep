/****
 * Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. 
 * Expected time complexity is O(Logn) 
 ****/
#include<bits/stdc++.h>
using namespace std;
int count(int arr[],int n,int x){
    int *low = lower_bound(arr,arr+n,x); //find first occurrence of x in arr
    if(low == (arr+n) || *low!=x){
        return 0;
    }
    int *high = upper_bound(arr,arr+n,x); //find last occurrence of x in arr

    return high-low; //count
}
int main(){
    int arr[] = {1, 2, 2, 3, 3, 3, 3};
    int x = 3; // Element to be counted in arr[]
    int n = sizeof(arr) / sizeof(arr[0]);
    int c = count(arr, n, x);
    cout<<x<<" Occurs "<<c<<" times";
    return 0;
}