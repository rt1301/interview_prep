#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
    int j = 0;
    for(int i=1;i<n;i++){
        int currentVal = arr[i];
        for( j=i-1;j>=0 && arr[j]>currentVal;j--){
            // Putting higher number in higher index
            arr[j+1] = arr[j];
        }
        // Putting the smaller number in previous index
        arr[j+1] = currentVal;
    }
}

void printArr(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    int a[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    int size = sizeof(a) / sizeof(a[0]);
    insertionSort(a, size);
    printArr(a, size);
    return 0;
}