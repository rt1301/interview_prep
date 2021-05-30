#include<bits/stdc++.h>
using namespace std;

void mergeHalves(int arr[],int helper[], int n, int low, int mid, int high){
    // Copy both the halves in the helper array
    for(int i=low;i<=high;i++){
        helper[i] = arr[i];
    }

    int helperLeft = low; // track start of left halve of helper arr
    int helperRight = mid+1; // track start of right halve of helper arr
    int current = low;
    // Iterate through the helper arr and compare the left & right halves
    // and copy the smaller of the two halves in the original arr
    while (helperLeft<=mid && helperRight<=high)
    {
        if(helper[helperLeft]<=helper[helperRight]){ // left halve is smaller
            arr[current] = helper[helperLeft];
            helperLeft++;
        }else{ // right halve is smaller
            arr[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }

    // copy the remaining elements of the left halve in the original array
    int remaining = mid - helperLeft;
    if(remaining>0){
        for (size_t i = 0; i < remaining; i++)
        {
            arr[current+i] = helper[helperLeft+i];
        }
    }
}

void mergeSort(int arr[], int helper[], int n, int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        mergeSort(arr, helper, n, low, middle);         // sort the left side
        mergeSort(arr, helper, n, middle + 1, high);    // sort the right side
        mergeHalves(arr, helper, n, low, middle, high); // merge the two halves
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
    int helper[size];
    mergeSort(a,helper,size,0,size-1);
    printArr(a,size);
    return 0;
}