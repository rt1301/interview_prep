#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    int small = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        small = i;
        for (size_t j = i+1; j < n; j++)
        {
            if(arr[j]<arr[small]){
                small = j;
            }
        }
        if(small != i ){
            swap(arr[small],arr[i]);
        }
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
    selectionSort(a, size);
    printArr(a, size);
    return 0;
}