#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class SinglyLL{
    Node *head = new Node();
    int size = 0;
    public:
    SinglyLL(){
        head = NULL;
    }
    void insert(int val){
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
            size++;
            return;
        }else{
            newNode->next = head;
            head = newNode;
            size++;
        }
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
    void insertAfter(int val, int index){
        Node*prev_node = get(index);
        if(prev_node == nullptr){
            cout<<"No such index found";
            return;
        }else{
            Node *newNode = new Node();
            newNode->data = val;
            newNode->next = nullptr;
            newNode->next = prev_node->next;
            prev_node->next = newNode;
            size++;
        }
    }
    void deleteNode(int position){
        if(position>=size || position<0){
            cout<<"Invalid Position\n";
            return;
        }
        if(position == 0){
            // remove head
            Node*temp = head;
            head = temp->next;
            size--;
            delete temp;
            return;
        }
        Node *prev_node = get(position-1);
        if(prev_node->next == nullptr || prev_node == nullptr){
            cout<<"Invalid Postion";
            return;
        }
        cout<<prev_node->data<<endl;
        Node *next = prev_node->next->next;
        delete prev_node->next;
        prev_node->next = next;
        size--;
    }
    Node *getHead(){
        return head;
    }
    Node *get(int index){
        if(index>=size || index<0){
            return NULL;
        }
        if(index == 0){
            return head;
        }
        else{
            Node *ref = head;
            while(index-- && ref->next!=nullptr){
                ref = ref->next;
            }
            return ref;
        }
    }
    void reverse(){
        // Initialize three pointers
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;
        while(curr != nullptr){
            next = curr->next; //next node
            curr->next = prev; //reversing process
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    int getSize(){
        return size;
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
    void reversePrint(Node *headRef){
        if(!headRef){
            return;
        }
        else{
            reversePrint(headRef->next);
            cout<<headRef->data<<" ";
        }
    }
};


int main(){
    SinglyLL a;
    a.insert(40);
    a.insert(50);
    a.insert(30);
    a.insert(30);
    a.push(100);
    a.insertAfter(60,2);
    a.deleteNode(5);
    a.printList();
    cout<<"\nAfter Reversing\n";
    // a.reverse();
    Node *head = a.getHead();
    a.reversePrint(head);
    return 0;
}