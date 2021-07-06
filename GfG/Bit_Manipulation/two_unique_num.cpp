/****
 * Given an array in which all numbers except two are repeated once.
 * (i.e. we have 2n+2 numbers and n numbers are occurring twice 
 * and remaining two have occurred once)
 * Find those two numbers in the most efficient way.  
 ****/
#include <bits/stdc++.h>
using namespace std;
int setbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
void uniqueNum(int arr[], int n)
{
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum ^= arr[i];
    }
    int temp = xorSum;
    int setBit = 0;
    int pos = 0;
    while (setBit != 1)
    {
        setBit = xorSum & 1;
        pos++;
        xorSum = xorSum >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setbit(arr[i], pos - 1))
        {
            newxor = newxor ^ arr[i];
        }
    }
    cout << "Two unique numbers are " << newxor << " and " << (temp ^ newxor);
}
int main()
{
    int arr[] = {2, 4, 6, 7, 4, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    uniqueNum(arr, n);
    return 0;
}