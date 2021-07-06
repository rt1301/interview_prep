#include<bits/stdc++.h>
using namespace std;

class Entity{
    private:
    float X, Y;
    public:
    // Default Constructor
    Entity(){
        X = 0.0f;
        Y = 0.0f;
        cout<<"Constructor Called\n";
    }
    // Parameterized Constructor
    Entity(float x, float y){
        X = x;
        Y = y;
    }
    // Copy Constructor
    Entity(Entity &e){
        X = e.X;
        Y = e.Y;
    }
    // Destructor
    ~Entity(){
        cout<<"Destructor Called!!\n";
    }
    void print(){
        cout<<"X = "<<X<<" & Y = "<<Y<<endl;
    }
};

int main(){
    Entity e(2.34,5.67);
    e.print();
    Entity e1;
    e1.print();
    Entity e2(e);
    e2.print();
    return 0;
}