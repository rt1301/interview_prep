// Aggregation in OOP
#include<bits/stdc++.h>
using namespace std;

class Address{
    public:
    string add,city,state;
    Address(string add, string city, string state){
        this->add = add;
        this->city = city;
        this->state = state;
    }
};

class Employee{
    private:
    Address *add; // Employee HAS-A Address
    public:
    string id, name;
    Employee(string id, string name, Address *add){
        this->id = id;
        this->name = name;
        this->add = add;
    }
    void display(){
        cout<<"Name of Employee: "<<name<<endl;
        cout<<"ID of Employee: "<<id<<endl;
        cout<<"Address Of Employee: "<<endl;
        cout<<add->add<<" , "<<add->city<<" , "<<add->state<<endl;
    }
};

int main(){
    Address a1= Address("Gautam Vihar, MG Road","Mumbai","MH");
    Employee e1 = Employee("01","Rishabh Taparia", &a1);
    e1.display();
    return 0;   
}