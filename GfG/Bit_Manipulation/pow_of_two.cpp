/****
 * Given a positive integer, write a function to find if it is a power of two or not.
 ****/
#include<bits/stdc++.h>
using namespace std;
bool isPow(int n){
    return (n && !(n & (n-1)));
}
int main(){
    int n = 1024;
    if(isPow(n)){
        cout<<n<<" is a power of two";
    }else{
        cout<<n<<" is not a power of two";
    }
    return 0;
}