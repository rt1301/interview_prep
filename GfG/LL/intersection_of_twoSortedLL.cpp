//Given two lists sorted in increasing order, 
//create and return a new list representing the intersection of the two lists. 
//The new list should be made 
//with its own memory — the original lists should not be changed. 
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
    Node(){
        next = nullptr;
        data = 0;
    }
};
class LL{
    Node *head = new Node();
    public:
    void push(Node*head,int val){
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    Node*getHead(){
        return head;
    }
    Node*commonNodes(Node*headA, Node*headB){
        Node*a = headA;
        Node*b = headB;
        Node*dummy = new Node();
        Node*tail = dummy;
        while(a && b){
            if(a == b){
                push(tail,a->data); //add common node to tail
                tail = tail->next; 
                a = a->next; //remove current a
                b = b->next; // remove current b
            }
            else if(a->data<b->data){
                a = a->next;
            }else{
                b = b->next;
            }
        }
        return dummy->next;
    }
    void printList(Node *head){
        Node *ref = head;
        if(ref == NULL){
            cout<<"Linked List is empty";
            return;
        }
        while (ref != NULL) {
            cout << ref->data << " ";
            ref = ref->next;
        }
        delete ref;
    }

};
void push(Node*head,int val){
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }else{
        newNode->next = head;
        head = newNode;
    }
}
Node*commonNodes(Node*headA, Node*headB){
    Node*a = headA;
    Node*b = headB;
    Node*dummy = new Node();
    Node*tail = dummy;
    while(a && b){
        if(a == b){
            push(tail,a->data); //add common node to tail
            tail = tail->next; 
            a = a->next; //remove current a
            b = b->next; // remove current b
        }
        else if(a->data<b->data){
            a = a->next;
        }else{
            b = b->next;
        }
    }
    return dummy->next;
}
void printList(Node *head){
    Node *ref = head;
    if(ref == NULL){
        cout<<"Linked List is empty";
        return;
    }
    while (ref != NULL) {
        cout << ref->data << " ";
        ref = ref->next;
    }
    delete ref;
}
int main(){
    LL a;
    LL b;
    Node*headA = a.getHead();
    Node*headB = b.getHead();
    a.push(headA,6);
    a.push(headA,5);
    a.push(headA,4);
    a.push(headA,3);
    a.push(headA,2);
    a.push(headA,1);
    b.push(headB,8);
    b.push(headB,6);
    b.push(headB,4);
    b.push(headB,2);
    a.printList(headA);
    b.printList(headB);
    Node*commonNode = commonNodes(headA,headB);
    printList(commonNode);
    
}