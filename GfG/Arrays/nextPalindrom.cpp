/****
 * Given a number, find the next smallest palindrome larger than this number.
 * For example, if the input number is “2 3 5 4 5”, the output should be “2 3 6 3 2”.
 * And if the input number is “9 9 9”, the output should be “1 0 0 1”. 
 * Difficulty - Hard
 ****/
#include<bits/stdc++.h>
using namespace std;

bool areAll9s(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i] != 9) return false;
    }
    return true;
}

void nextPalindromeUtil(int arr[],int n){
    int m = n/2; // mid element
    int i = m-1; // left ptr will always be one before the mid
    int j = (n%2)? m+1:m; // right ptr will depend on whether n is even or odd
    bool leftSmaller = false; // to check if left half is smaller than right half

    while (i>=0 && arr[i] == arr[j]) // ignore all the same elements in 
    {                                // in both halves
        i--;
        j++;
    }
    
    // check if the left half is smaller than the right half
    if(i<0 || arr[i]<arr[j]) leftSmaller = true;
    // mirror the left half to right half
    while (i>=0)
    {
        arr[j] = arr[i];
        i--;
        j++;
    }
    // handle the case when the middle digits need to be incremented
    if(leftSmaller){
        int carry = 1;
        i = m-1;
        // if n is odd
        // increment the mid digit by one and store the carry
        if(n%2 == 1){
            arr[m]+=carry;
            carry = arr[m]/10;
            arr[m] = arr[m]%10;
            j = m+1;
        }else j = m;

        // add 1 to the rightmost bit of the left side
        // propagate the carry to the MSB and simultaneously
        // copying the left side to the right side
        while(i>=0){
            arr[i]+=carry;
            carry = arr[i]/10;
            arr[i]%=10;
            arr[j++] = arr[i--]; // copy mirror to the right side
        }
    }

}
void printArr(int arr[],int n){
    for (size_t i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
void generateNextPalindrome(int arr[],int n){
    if(areAll9s(arr,n)){
        cout<<"1 ";
        for (size_t i = 0; i < n; i++)
        {
            cout<<"0 ";
        }
        cout<<"1";
    }else{
        nextPalindromeUtil(arr,n);
        printArr(arr,n);
    }
}

int main()
{
    int num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};

    int n = sizeof(num) / sizeof(num[0]);

    generateNextPalindrome(num, n);

    return 0;
}