/****
 * Given an array and a value, find if there is a triplet
 * in array whose sum is equal to the given value. 
 * If there is such a triplet present in array,
 * then print the triplet and return true. Else return false.
 ****/

#include<bits/stdc++.h>
using namespace std;
// Time Complexity O(n^2) and Space Complexity O(1);
bool isSum(int arr[],int n, int x){
    sort(arr,arr+n);
    int l = 0;
    int r = n-1;
    // Now fix the first element one by one and find the
    // other two elements 
    for (int i = 0; i < n - 2; i++)
    {
        l = i+1;
        r = n-1;
        while (l<r)
        {
            // To find the other two elements, start two index
            // variables from two corners of the array and move
            // them toward each other
            if(arr[l] + arr[r] + arr[i] == x){
                cout<<arr[l]<<" "<<arr[r]<<" "<<arr[i]<<endl;
                return true;
            }
            if ((arr[l] + arr[r] + arr[i])<x){
                l++;
            }else{
                r--;
            }
        }
    }
    cout<<"No such triplet found";
    return false;
    
}


int main(){
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int n = sizeof(A) / sizeof(A[0]);
    isSum(A,n,sum);
    return 0;
}