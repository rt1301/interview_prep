#include<bits/stdc++.h>
using namespace std;
// Single Inheritance
class Parent{
    public:
    int pt_id;
};

class Child : public Parent{
    public:
    int child_id;
};
 
// Multiple Inheritance
class A{
    public:
    void funcA(){
        cout<<"Function in class A\n";
    }
};

class B{
    public:
    void funcB(){
        cout<<"Function in Class B\n";
    }
};

class C : public A, public B{
    public:
};
// Multilevel Inheritance
class Vehicle{
    public:
    Vehicle(){
        cout<<"This is a Vehicle\n";
    }
};
class fourWheeler:public Vehicle{
    public:
    fourWheeler(){
        cout<<"A 4 Wheeler Vehicle\n";
    }
};
class Car:public fourWheeler{
    public:
    Car(){
        cout<<"Car is a 4 wheeler vehicle\n";
    }
};
int main(){
    Child c;
    c.child_id = 1;
    c.pt_id = 10;
    cout<<"Child id is "<<c.child_id<<endl;
    cout<<"Parent id is "<<c.pt_id<<endl;
    // Multiple Inheritance
    C obj;
    obj.funcA();
    obj.funcB();
    // Multilevel Inheritance
    Car obj1;
    return 0;
}