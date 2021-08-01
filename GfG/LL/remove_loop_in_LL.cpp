/****
 * Given a linked list of N nodes such that it may contain a loop. 
 * A loop here means that the last node of the link list is connected 
 * to the node at position X. If the link list does not have any loop, X=0.
 * Remove the loop from the linked list, if it is present.  
 ****/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void detectLoop(Node *head)
    {
        if (!head)
            return;
        Node *slow_p = head, *fast_p = head;
        while (slow_p && fast_p && fast_p->next)
        {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;

            if (slow_p == fast_p)
            {
                break;
            }
        }
        if (slow_p == fast_p)
        {
            slow_p = head;
            if (slow_p == fast_p)
            {
                while (fast_p->next != slow_p)
                    fast_p = fast_p->next;
            }
            else
            {
                while (slow_p->next != fast_p->next)
                {
                    slow_p = slow_p->next;
                    fast_p = fast_p->next;
                }
            }
            fast_p->next = NULL;
        }
    }
    //Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // code here
        // just remove the loop without losing any nodes
        detectLoop(head);
    }
};