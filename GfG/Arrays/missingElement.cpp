/****
 * You are given a list of n-1 integers and these integers are in the range of 1 to n
 * There are no duplicates in the list. One of the integers is missing in the list
 * Write an efficient code to find the missing integer.
 ****/
#include<bits/stdc++.h>
using namespace std;

int missingEl(int arr[],int n){
    int sum = (n+1)*(n+2)*0.5;
    int s = 0;
    for (size_t i = 0; i < n; i++)
    {
        s+=arr[i];
    }
    return sum-s;
}
// Modified code to avoid integer overflow
int missingElUpdated(int arr[], int n){
    int sum = 1;
    for (size_t i = 2; i < n; i++)
    {
        sum+=i;
        sum-=(arr[i-2]);
    }
    return sum;
}
int main(){
    int arr[] = {1, 2, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = missingEl(arr, n);
    cout << miss;
    return 0;
}