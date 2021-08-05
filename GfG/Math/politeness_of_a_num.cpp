/****
 * Given an integer n. Find politeness of number n. 
 * The politeness of a number is defined as the number of ways it 
 * can be expressed as the sum of consecutive integers. 
 ****/
#include<bits/stdc++.h>
using namespace std;

int countOddFactors(int n){
    while(n%2 == 0){
        n/=2;
    }
    int res = 1;
    // n must be odd at this point,
    // so iterate for only
    // odd numbers till sqrt(n)
    for(int i=3;i<=sqrt(n);i++){
        int divCount = 0;
        // if i divides n, then start counting of
        // Odd divisors
        while(n%i == 0){
            divCount++;
            n/=i;
        }
        res*=divCount+1;
    }
    if(n>2){
        res*=2;
    }
    return res;
}
int politeness(int n){
    return countOddFactors(n)-1;
}
int main(){
    int n = 90;
    cout << "Politness of " << n << " = "
         << politeness(n) << "\n";

    n = 15;
    cout << "Politness of " << n << " = "
         << politeness(n) << "\n";
    return 0;
}