/****
 * There are two sorted arrays. First one is of size m+n containing only m elements.
 * Another one is of size n and contains n elements. 
 * Merge these two arrays into the first array of size m+n such that the output is sorted. 
 ****/
#include<bits/stdc++.h>
using namespace std;
#define NA -1;
void moveElements(int arr[],int n){
    int j = n-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i] != -1){
            arr[j] = arr[i];
            j--;
        }
    }
}

void merge(int mNplus[],int N[],int m,int n){
    int i = n;
    int j = 0;
    int k = 0;

    while(k<(m+n)){
        // take element from m+n array if
        // a) it is smaller and we haven't reached end of m+n arr OR
        // b) we have reached end of N arr
        if(j==n || (i<(m+n) && mNplus[i]<=N[j])){
            mNplus[k] = mNplus[i];
            i++;
            k++;
        }
        else{ //take element from N[]
            mNplus[k] = N[j];
            j++;
            k++;
        }
    }
}
void printArr(int arr[],int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    /* Initialize arrays */
    int mPlusN[] = {2, 8, -1, -1, -1, 13, -1, 15, 20};
    int N[] = {5, 7, 9, 25};

    int n = sizeof(N) / sizeof(N[0]);
    int m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;

    /*Move the m elements at the end of mPlusN*/
    moveElements(mPlusN, m + n);

    /*Merge N[] into mPlusN[] */
    merge(mPlusN, N, m, n);

    /* Print the resultant mPlusN */
    printArr(mPlusN, m + n);
    return 0;
}