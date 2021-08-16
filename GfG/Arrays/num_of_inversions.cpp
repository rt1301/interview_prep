#include<bits/stdc++.h>
using namespace std;
int merge_util(int arr[],int temp[],int left,int mid, int right){
    int inv_count = 0;
    int i=left,j=mid,k=left;
    while ((i<=(mid-1) && j<=right))
    {
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            // Inversion count step
            // all the elements in the left of i will be larger
            // than i and hence can be used to form a pair
            inv_count+=(mid-i);
        }
    }

    while (i<=(mid-1))
    {
        temp[k++] = arr[i++];
    }
    while (j<=right)
    {
        temp[k++] = arr[j++];
    }

    for(int i=left;i<=right;i++){
        arr[i] = temp[i];
    }
    return inv_count;
}
int mergeSort(int arr[],int temp[], int left, int right){
    int inv_count=0;
    if(right>left){
        int mid = left + (right-left)/2;
        inv_count+= mergeSort(arr,temp,left,mid);
        inv_count+= mergeSort(arr,temp,mid+1,right);
        inv_count+=merge_util(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int main(){
    int arr[] = {8,4,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    cout<<mergeSort(arr,temp,0,n-1);
    return 0;
}