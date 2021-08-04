/****
 * Given two sorted linked lists consisting of N and M nodes respectively. 
 * The task is to merge both of the list (in-place) and return head of the merged list.
 ****/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *sortedMerge(Node *head1, Node *head2)
{
    // code here
    Node *temp = new Node(0);
    Node *res = temp;
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if (head1)
        temp->next = head1;
    else
        temp->next = head2;

    return res->next;
}