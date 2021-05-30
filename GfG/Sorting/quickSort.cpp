#include<bits/stdc++.h>
using namespace std;
int partitionEls(int arr[],int n, int left, int right){
    int pivot = arr[(left+right)/2];
    while (left<=right)
    {
        // find the element on the left that should be on the right
        while(arr[left]<pivot) left++;
        // find the element on right that should be on the left
        while(arr[right]>pivot) right--;
        // swap elements and move left and right indices
        if(left<=right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quickSort(int arr[],int n, int left, int right)
{
    int index = partitionEls(arr,n,left,right);
    if(left<index-1){ // sort the left side
        quickSort(arr,n,left,index-1);
    }
    if(right>index){ // sort the right side
        quickSort(arr,n,index,right);
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
    
    quickSort(a,size,0,size-1);
    printArr(a, size);
    return 0;
}