// Given a linked list of 0s, 1s and 2s, sort it.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
};

void sortList(Node *head){
    int n1=0,n2=0,n3=0;
    Node *ref = head;
    while (ref)
    {
        if(ref->data == 1){
            n2++;
        }else if(ref->data == 2){
            n3++;
        }else{
            n1++;
        }
        ref = ref->next;
    }
    ref = head;
    int count = 0;
    while (count<n1 && ref)
    {
        ref->data = 0;
        ref = ref->next;
        count++;
    }
    count = 0;
    while(count<n2 && ref){
        ref->data = 1;
        ref = ref->next;
        count++;
    }
    count = 0;
    while(count<n3 && ref){
        ref->data = 2;
        ref = ref->next;
        count++;
    }
    
}
/* Function to push a node */
void push (Node** head_ref, int new_data)
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
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
 
/* Driver code*/
int main(void)
{
    Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
 
    cout << "Linked List Before Sorting\n";
    printList(head);
 
    sortList(head);
 
    cout << "Linked List After Sorting\n";
    printList(head);
 
    return 0;
}