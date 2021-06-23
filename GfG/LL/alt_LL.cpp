//Write a function AlternatingSplit() that takes one list and 
//divides up its nodes to make two smaller lists ‘a’ and ‘b’. 
//The sublists should be made from alternating elements in the original list. 
//So if the original list is 0->1->0->1->0->1 then one sublist 
//should be 0->0->0 and the other should be 1->1->1. 
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
};
void moveNode(Node **destRef, Node**srcRef){
    Node*newNode = *srcRef;

    *srcRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}
void altLL(Node *head, Node**aRef, Node**bRef){
    Node*a = nullptr;
    Node*b = nullptr;
    Node*ref = head;
    while(ref){
        moveNode(&a, &ref);
        if(ref!=nullptr){
            moveNode(&b,&ref);
        }
        // ref = ref->next;
    }
    *aRef = a;
    *bRef = b;
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
int main(){
    /* Start with the empty list */
    Node* head = NULL;
    Node* a = NULL;
    Node* b = NULL;
     
    /* Let us create a sorted linked list to test the functions
    Created linked list will be 0->1->2->3->4->5 */
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);                                
    push(&head, 0);
     
    cout<<"Original linked List: ";
    printList(head);
     
    /* Remove duplicates from linked list */
    altLL(head, &a, &b);
     
    cout<<"\nResultant Linked List 'a' : ";
    printList(a);        
     
    cout<<"\nResultant Linked List 'b' : ";
    printList(b);        
     
    return 0;
}