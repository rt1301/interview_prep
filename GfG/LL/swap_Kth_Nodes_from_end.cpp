/****
 * Given a singly linked list of size N, and an integer K. 
 * You need to swap the Kth node from the beginning and Kth node from 
 * the end of the linked list. Swap the nodes through the links. 
 * Do not change the content of the nodes.
 ****/
#include<bits/stdc++.h>
using namespace std;
Node *swapkthnode(Node *head, int num, int K)
{
    // Your Code here
    if (K > num)
    {
        return head;
    }
    if (2 * K - 1 == num)
    {
        return head;
    }
    Node *b = head;
    Node *b_prev = NULL;
    int count = K;
    while (b && count > 1)
    {
        b_prev = b;
        b = b->next;
        count--;
    }
    Node *e = head;
    Node *e_prev = NULL;
    count = num - K + 1;
    while (e && count > 1)
    {
        e_prev = e;
        e = e->next;
        count--;
    }
    if (b_prev)
    {
        b_prev->next = e;
    }
    if (e_prev)
    {
        e_prev->next = b;
    }
    Node *temp = b->next;
    b->next = e->next;
    e->next = temp;
    if (K == 1)
    {
        head = e;
    }
    if (K == num)
    {
        head = b;
    }
    return head;
}