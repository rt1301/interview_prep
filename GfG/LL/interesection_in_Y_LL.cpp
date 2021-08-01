/****
 * Given two singly linked lists of size N and M, write a program 
 * to get the point where two linked lists intersect each other.
 ****/
#include <bits/stdc++.h>
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

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    unordered_set<Node *> st;
    Node *ref1 = head1;
    while (ref1)
    {
        st.insert(ref1);
        ref1 = ref1->next;
    }
    while (head2)
    {
        if (st.find(head2) != st.end())
        {
            return head2->data;
        }
        head2 = head2->next;
    }
    return -1;
}