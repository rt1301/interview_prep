#include<bits/stdc++.h>
using namespace std;
void printRev(string s, int n){
    if (n == 0){
        return;
    }
    cout<<s[n-1];
    printRev(s,n-1);
}
int main(){
    string s = "HelloWorld";
    int n = s.length();
    printRev(s,n);
    return 0;
}