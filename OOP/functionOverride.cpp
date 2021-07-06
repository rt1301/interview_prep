#include<bits/stdc++.h>
using namespace std;
class base{
    public:
    virtual void print(){
        cout<<"This is base class print function\n";
    }
    virtual void display(){
        cout<<"This is base class display function\n";
    }
};

class derived:public base{
    public:
    void print(){
        cout<<"This is derived class print function\n";
    }
    void display(){
        cout<<"This is derived class display function\n";
    }
};

int main()
{
    base *baseptr;
    derived obj;
    baseptr = &obj;
    baseptr->print();
    baseptr->display();
    return 0;
}