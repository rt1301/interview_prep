#include <bits/stdc++.h>
using namespace std;
class encapsulation
{
private:
    int a;
    void funcA(){
        cout<<"Function A\n";
    }
protected:
    int b;
    void funcB(){
        cout<<"Function B\n";
    }
public:
    int c;
    void funcD(){
        funcA();
    }
    void funcC(){
        cout<<"Function C\n";
    }
    
};

int main(){
    encapsulation obj;
    obj.c = 20;
    cout<<"Public Data variable\t"<<obj.c<<endl;
    obj.funcC();
    cout<<"Accessing Private Member Function\n";
    obj.funcD();
    return 0;
}

