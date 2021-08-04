#include<bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *helper(Node *head)
    {
        Node *curr = head, *tail = head;
        while (curr)
        {
            Node *child = curr->child;
            Node *next = curr->next;
            if (child)
            {
                Node *t = helper(child);

                t->next = next;
                if (next)
                    next->prev = t;

                curr->next = child;
                child->prev = curr;

                curr->child = nullptr;

                curr = t;
            }
            else
            {
                curr = next;
            }
            if (curr)
            {
                tail = curr;
            }
        }
        return tail;
    }
    Node *flatten(Node *head)
    {
        if (head)
            helper(head);
        return head;
    }
};