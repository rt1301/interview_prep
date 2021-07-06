#include<bits/stdc++.h>
using namespace std;

class base_class{
    public:
    void fun(){
        cout<<"This is a function with no arguments"<<endl;
    }
    void fun(int x){
        cout<<"This is a function with int argument "<<x<<endl;
    }
    void fun(double x){
        cout<<"This is a function with double argument "<<x<<endl;
    }
};

int main(){
    base_class obj;
    obj.fun();
    obj.fun(4);
    obj.fun(2.32);
    return 0;
}