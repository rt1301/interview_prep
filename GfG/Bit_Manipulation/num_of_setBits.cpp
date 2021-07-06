/****
 * Write an efficient program to count the number 
 * of 1s in the binary representation of an integer.
 ****/
#include<bits/stdc++.h>
using namespace std;

int numOfOnes(int n){
    int count = 0;
    while (n != 0)
    {
        n = (n & (n-1));
        count++;
    }
    return count;
}

int main(){
    int n = 13;
    cout<<numOfOnes(n);
    return 0;
}