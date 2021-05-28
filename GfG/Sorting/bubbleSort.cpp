#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
void printArr(int arr[],int n){
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int size = sizeof(a)/sizeof(a[0]);
    bubbleSort(a,size);
    printArr(a,size);
    return 0;
}