/****
 * Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, 
 * continue the same till end of the linked list.
 * Input:
    M = 2, N = 2
    Linked List: 1->2->3->4->5->6->7->8
    Output:
    Linked List: 1->2->5->6
 ****/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
};
void deleteNode(Node *head, int m, int n){
    Node*curr = head;
    Node*prev = nullptr;
    int count = 0;
    // Main Loop which traverses through the LL
    while (curr)
    {
        count = 1;
        // Skip M nodes
        while (curr && count<m)
        {
            curr = curr->next;
            count++;
        }
        if (curr == NULL)
            return;
        count = 0;
        // Make the prev pointer point at curr
        // Shift curr by 1
        prev = curr;
        curr = curr->next;
        // Delete N nodes
        while (curr && count<n)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count++;
        }
        
    }
    
}

/* Function to insert a node at the beginning */
void push(Node ** head_ref, int new_data)
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
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    /* Create following linked list
    1->2->3->4->5->6->7->8->9->10 */
    Node* head = NULL;
    int M=2, N=3;
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout << "M = " << M<< " N = " << N << "\nGiven Linked list is :\n";
    printList(head);
 
    deleteNode(head, M, N);
 
    cout<<"\nLinked list after deletion is :\n";
    printList(head);
 
    return 0;
}