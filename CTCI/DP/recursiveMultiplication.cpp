// Multiply two numbers without using traditional * operator
// Use minimum number of addition, subtraction, bitwise operations
#include<bits/stdc++.h>
using namespace std;
int recursiveMulHelper(int memo[],int smaller,int bigger){
    if(smaller == 0){
        // 0 X bigger = 0
        return 0;
    }
    if(smaller == 1){
        // 1 X bigger = bigger
        return bigger;
    }
    if(memo[smaller]>0){
        return memo[smaller];
    }
    // Check if size is even or odd
    int size = smaller/2;
    int side1 = recursiveMulHelper(memo,size,bigger);
    int side2 = side1;
    if(smaller % 2 == 1){
        side2 = recursiveMulHelper(memo,smaller-size,bigger);
    }
    memo[smaller] = side1+side2;
    return memo[smaller];
}
// Optimised solution by using the logic that
// in odd size-> answer is twice the grid cells + bigger number
int optimisedMul(int smaller, int bigger){
    if(smaller ==0) return 0;
    if(smaller == 1) return bigger;
    int s = smaller/2;
    int halfProduct = optimisedMul(s,bigger);
    if(smaller%2==1){
        return halfProduct + halfProduct + bigger;
    }else{
        return halfProduct + halfProduct;
    }
}
int recursiveMul(int a, int b){
    int smaller = a>b?b:a;
    int bigger = a>b?a:b;
    int memo[smaller+1];
    for(int i=0;i<smaller+1;i++) memo[i] = -1;
    // return recursiveMulHelper(memo,smaller,bigger); 
    return optimisedMul(smaller,bigger);
}

int main(){
    cout<<recursiveMul(8,7);
    return 0;
}