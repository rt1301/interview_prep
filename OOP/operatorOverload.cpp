#include<bits/stdc++.h>
using namespace std;
class Complex{
    private:
    int real;
    int imag;
    public:
    Complex(int r=0, int i=0){
        real = r;
        imag = i;
    }
    Complex operator+ (Complex &obj){
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void display(){
        cout<<real<<" + i"<<imag<<endl;
    }
};
int main(){
    Complex c1(10,5),c2(15,30);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}