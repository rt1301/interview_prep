/****
 * Given two linked lists, insert nodes of second list into 
 * first list at alternate positions of first list. 
 * For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, 
 * the first list should become 5->12->7->10->17->2->13->4->11->6 
 * and second list should become empty.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*next;
    int data;
};
/* Function to insert a node at the beginning */
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Utility function to print a singly linked list */
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void mergeLL(Node*l1, Node**l2){
    Node*curr = l1;
    Node*curr2 = *l2;
    Node*next = nullptr;
    Node*next2 = nullptr;
    while (curr && curr2)
    {
        next = curr->next;
        next2 = curr2->next;

        curr2->next = next;
        curr->next = curr2;

        curr = next;
        curr2 = next2;
    }
    *l2 = curr2;
}
int main(){
    Node *p = NULL, *q = NULL;
    push(&p, 3);
    push(&p, 2);
    push(&p, 1);
    cout << "First Linked List:\n";
    printList(p);

    push(&q, 8);
    push(&q, 7);
    push(&q, 6);
    push(&q, 5);
    push(&q, 4);
    cout << "Second Linked List:\n";
    printList(q);

    mergeLL(p, &q);

    cout << "Modified First Linked List:\n";
    printList(p);

    cout << "Modified Second Linked List:\n";
    printList(q);

    return 0;
}