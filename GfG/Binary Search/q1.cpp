/****
 * Given a sorted array of N distinct elements. 
 * Find a key in the array using least number of comparisons.
 ****/
#include<bits/stdc++.h>
using namespace std;
// In the while loop we are depending only on one comparison. Whereas in the traditional Binary search we
// use 2 comparison in per iteration
int binarySearch(int arr[],int n,int key){
    int l = 0;
    int r = n-1;
    int m;
    while ((r-l)>1)
    {
        m = l + (r-l)/2;
        if(arr[m]<=key){
            l = m;
        }else{
            r = m;
        }
        
    }
    if(arr[l] == key) return l;
    if(arr[r] == key) return r;
    return -1;
    
}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int index = binarySearch(a,10,5);
    cout<<index;
    return 0;
}