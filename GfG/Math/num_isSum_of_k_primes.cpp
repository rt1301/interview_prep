/****
 * Given two numbers N and K. We need to find out if ‘N’ can be written 
 * as sum of ‘K’ prime numbers. 
 * Given N <= 10^9
 ****/
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

bool checkSumIsOfPrimes(int n, int k){
    if(n<(2*k)){
        return false;
    }

    if(n>=(2*k) && k==1){
        return isPrime(n);
    }

    if(n>=(2*k) && k == 2){
        if(n%2 == 0){
            return true;
        }else{
            return isPrime(n-2);
        }
    }

    if(k>=3){
        return true;
    }

}