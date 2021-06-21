#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
};
Node* reverseNodes(Node*head, int k){
    // if(!head) return head;
    Node*prev = nullptr;
    Node*curr = head;
    Node*next = nullptr;
    int count = 0;
    // Reverse first K nodes of the Linked List
    while (curr && count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // Now head points to kth Node
    // So change next of head as k+1 node 
    if(head){
        head->next = curr;
    }
    // We don't want the next k nodes in our reversed list
    count = 0;
    while(curr && count<k-1){
        curr = curr->next;
        count++;
    }
    // Recursively call for the list
    //starting from current->next. And make
    //rest of the list as next of first node
    if(curr){
        curr->next = reverseNodes(curr->next,k);
    }
    return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
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
void printList(Node *node)
{
    int count = 0;
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
        count++;
    }
}
 
/* Driver code*/
int main(void)
{
    /* Start with the empty list */
    Node* head = NULL;
    int i;
     
    // create a list 1->2->3->4->5...... ->20
    for(i = 20; i > 0; i--)
    push(&head, i);
 
    cout<<"Given linked list \n";
    printList(head);
    head = reverseNodes(head, 3);
 
    cout<<"\n Modified Linked list \n";
    printList(head);
    return(0);
}