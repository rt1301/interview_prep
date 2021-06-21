// Given a singly linked list, rotate the linked list counter-clockwise by k nodes. 
// Where k is a given positive integer. For example, if the given linked list is 
// 10->20->30->40->50->60 and k is 4, 
// the list should be modified to 50->60->10->20->30->40. 
// Assume that k is smaller than the count of nodes in a linked list.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
};

void rotateLL(Node **head, int k){
    if(k == 0) return;
    Node*curr = *head;
    Node*last = nullptr;
    Node*next = nullptr;
    Node*store = nullptr;
    while(k>1 && curr){
        curr = curr->next;
        k--;
    }
    store = curr;
    next = curr->next;
    if(curr == nullptr) return;
    while(curr->next){
        curr = curr->next;
    }
    last = curr;
    store->next = nullptr;
    last->next = *head;
    *head = next;
}
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
int main(){
    /* Start with the empty list */
    Node* head = NULL;
 
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    cout << "Given linked list \n";
    printList(head);
    rotateLL(&head, 4);
 
    cout << "\nRotated Linked list \n";
    printList(head);
    return 0;
}