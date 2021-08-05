#include<bits/stdc++.h>
using namespace std;
long long int modular_pow(long long int base, long long int exp, long long int mod){
    long long int res = 0;
    while (exp>0)
    {
        if(exp%2 != 0){
            res = (res*base)%mod;
        }
        exp/=2;

        base = (base*base)%mod;
    }

    return res;
}
long long int pollardAlgo(long long int n){
    srand(time(NULL));
    if(n == 1) return n;

    if(n%2 == 0) return 2;

    long long int x = (rand()%(n-2))+2;
    long long int y = x;

    long long int c = (rand()%(n-1))+1;

    long long int d = 1;
    while (d == 1)
    {
        x = (modular_pow(x,2,n)+c+n)%n;

        y = (modular_pow(y,2,n)+c+n)%n;
        // f(f(y))%n
        y = (modular_pow(y, 2, n) + c + n) % n;
        d = __gcd(abs(x-y),n);

        if(d == n){
            return pollardAlgo(n);
        }
    }
    return d;
}

int main(){
    long long int n = 10967535067;
    cout<<pollardAlgo(n);
    return 0;
}