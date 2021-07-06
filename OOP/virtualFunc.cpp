// Virtual Functions
#include<bits/stdc++.h>
using namespace std;

class Entity{
    public:
    virtual string getName(){
        return "Entity";
    }
};

class Player : public Entity{
    private:
    string name;
    public:
    Player(string n){
        this->name = n;
    }
    string getName(){
        return name;
    }
};

void printName(Entity* e){
    cout<<e->getName()<<endl;
}

int main(){
    Entity* e = new Entity();
    Player* p = new Player("Rishabh");
    printName(e);
    printName(p);
    return 0;
}