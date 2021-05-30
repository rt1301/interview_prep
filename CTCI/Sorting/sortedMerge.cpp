#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int b[],int m,int n){
    int indexA = m-1;
    int indexB = n-1;
    int mergedIndex = m+n-1;
    // merge b into a starting from the last element
    while (indexB>=0 && indexA>=0)
    {
        if(indexA<0){
            while(indexB>=0){
                a[mergedIndex] = b[indexB];
                indexB--;
                mergedIndex--;
            }
            break;
        }
        // if ele in a is greater than ele in b
        if(a[indexA]>b[indexB]){
            a[mergedIndex] = a[indexA]; // copy element
            indexA--;
        }else{
            a[mergedIndex] = b[indexB]; // copy element
            indexB--;
        }
        mergedIndex--;
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
    int A[5] = {1, 3, 5, 7, 9};
    int B[4] = {2, 4, 6, 8};

    // print arrays before
    std::cout << "\nArray A before: ";
    printArr(A,5);
    std::cout << "\nArray B before: ";
    printArr(B,4);
    merge(A, B, 5, 4);

    // print merged array
    int total_size = 4 + 5;
    std::cout << "\nMerged Array: ";
    printArr(A,total_size);
    return 0;
}