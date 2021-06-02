/****
 * Given an array arr[] of integers, find out the maximum difference
 * between any two elements such that larger element appears after the smaller number. 
 *  Input : arr = {2, 3, 10, 6, 4, 8, 1}
    Output : 8
    Explanation : The maximum difference is between 10 and 2.
 ****/
#include<bits/stdc++.h>
using namespace std;
// Brute Force Solution - O(n^2)
int maxDifference(int arr[],int n){
    int diff = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                diff = max(diff, abs(arr[i] - arr[j]));
            }
        }
    }
    return diff;
}
// Optimised Solution - O(n)
// Check difference between current element and
// minimum element so far
// Solution assumes that array has minimum two elements
// it returns -1 for decreasing sorted arr
// and returns 0 if the elements are equal
int maxDifferenceOptimised(int arr[],int n){
    int max_diff = arr[1] - arr[0]; // max difference so far
    int min_element = arr[0]; // min element found so far
    for(int i=0;i<n;i++){
        if(arr[i]-min_element>max_diff){
            max_diff = arr[i]-min_element;
        }
        if(arr[i]<min_element){
            min_element = arr[i];
        }
    }
    return max_diff;
}
int main(){
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = maxDifferenceOptimised(arr,n);
    cout<<ans<<endl;
    return 0;
}