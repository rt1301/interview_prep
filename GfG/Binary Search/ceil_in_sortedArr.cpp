#include<bits/stdc++.h>
using namespace std;
int ceilEle(int arr[],int n,int key){
    int ceil = 0;
    // linear search
    // for(int i=0;i<n;i++){
    //     if(arr[i]>=key){
    //         ceil = arr[i];
    //         break;
    //     }
    // }
    // Binary Search
    int l = 0;
    int r = n-1;
    int m;
    while ((r-l)>1)
    {
        m = l + (r-l)/2;
        if(arr[m]>= key){
            r = m;
        }else{
            l = m;
        }
    }
    if(arr[l]>=key) return arr[l];
    if(arr[r]>=key) return arr[r];
    return 0;
    // return ceil;
}
int main(){
    int a[7] = {1, 2, 8, 10, 10, 12, 19};
    int x = 0;
    cout << ceilEle(a, 7, x) << endl;
    x = 1;
    cout << ceilEle(a, 7, x) << endl;
    x = 5;
    cout << ceilEle(a, 7, x) << endl;
    x = 20;
    cout << ceilEle(a, 7, x) << endl;
    return 0;
}