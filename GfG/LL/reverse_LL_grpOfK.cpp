/****
 * Given a linked list of size N. The task is to reverse every 
 * k nodes (where k is an input to the function) in the linked list.
 ****/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        // Complete this method
        int i = 0;
        struct node *prev = NULL;
        struct node *curr = head;
        struct node *next = NULL;
        while (curr && i < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        if (head)
        {
            if (curr)
            {
                head->next = reverse(curr, k);
            }
        }
        return prev;
    }
};