// Friend Function
#include<bits/stdc++.h>
using namespace std;

class A{
    private:
    int a = 10;
    int b = 30;
    public:
    friend int mult(A obj){
        return obj.a*obj.b;
    }
};

int main(){
    A obj;
    int res;
    res = mult(obj);
    cout<<res;
    return 0;
}