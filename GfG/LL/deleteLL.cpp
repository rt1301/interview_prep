#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node*next;
    int data;
};
class LL{
    Node *head = new Node();
    int size = 0;
    public:
    void deleteLL(){
        Node*curr = head;
        Node*next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
    }
    void push(int val){
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if(head == NULL){
            head = newNode;
            size++;
            return;
        }else{
            Node *ref = head;
            while (ref->next !=NULL)
            {
                ref = ref->next;
            }
            ref->next = newNode;
            size++;
        }
    }
    void printList(){
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
int main(){
    LL a;
    a.push(40);
    a.push(50);
    a.push(30);
    a.push(30);
    a.push(100);
    a.printList();
    cout<<"\nLL Deleted\n";
    a.deleteLL();
    a.printList();
    return 0;
}