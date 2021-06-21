//Given a Singly Linked List, starting from the second node 
//delete all alternate nodes of it. For example, if the given linked 
//list is 1->2->3->4->5 then your function should convert it to 1->3->5, 
//and if the given linked list is 1->2->3->4 then convert it to 1->3.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
};
void deleteAltNode(Node *head){
    if(head == nullptr){
        cout<<"LL is empty\n";
        return;
    }
    Node*prev = head;
    Node*curr = head->next;
    while (curr != nullptr && prev!=nullptr)
    {
       prev->next = curr->next;
       delete curr;
       prev = prev->next;
       if(prev){
           curr = prev->next;
       }
    }
    
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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout<< node->data<<" ";
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Using push() to construct below list
    1->2->3->4->5 */
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout<<"List before calling deleteAlt() \n";
    printList(head);
 
    deleteAltNode(head);
 
    cout<<"\nList after calling deleteAlt() \n";
    printList(head);
 
    return 0;
}