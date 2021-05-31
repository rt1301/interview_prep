/****
 * Given an unsorted array that contains even number of occurrences 
 * for all numbers except two numbers. 
 * Find the two numbers which have odd occurrences in O(n)
 * time complexity and O(1) extra space.
 ****/
#include<bits/stdc++.h>
using namespace std;
void findOddOccurrences(int arr[],int size){
    int xor2 = arr[0]; // it will hold the XOR of two odd occurring elements
    int set_bit_no; //it will have the single set bit of xor2
    int n = size-2;
    int x=0,y=0; // our two odd occurring elements

    // find all the XORs of the elements of the arr
    for (int i = 1; i < size; i++)
    {
        xor2^=arr[i];
    }
    // we are using the rightmost bit as the setbit
    // coz it is simpler to get
    set_bit_no = xor2 & ~(xor2-1);

    // Divide the original array in two parts such that
    // 1) Numbers with the corressponding bit as 1
    // 2) Numbers with the corressponding bit as 0
    for(int i=0;i<size;i++){
        // XOR of the first set will finally hold one odd occurring number
        if(arr[i] & set_bit_no){
            x = x ^ arr[i];
        }else{
            // XOR of the second set will finally hold the other odd occurring
            // number
            y = y ^ arr[i];
        }
    }
    cout << "The two ODD elements are " << x << " & " << y;
}

int main(){
    int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    findOddOccurrences(arr,arr_size);
    return 0;
}