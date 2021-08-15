/****
 * You are given a special linked list with N nodes where each node has a next pointer 
 * pointing to its next node. You are also given M random pointers, where you will 
 * be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.
 * 
 * Construct a copy of the given list. The copy should consist of exactly N new 
 * nodes, where each new node has its value set to the value of its corresponding 
 * original node. Both the next and random pointer of the new nodes should point to 
 * new nodes in the copied list such that the pointers in the original list and copied list 
 * represent the same list state. None of the pointers in the new list should 
 * point to nodes in the original list.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *ogCurr = head;
        Node *cloneCurr = NULL;

        unordered_map<Node *, Node *> mp;

        while (ogCurr)
        {
            cloneCurr = new Node(ogCurr->data);
            mp[ogCurr] = cloneCurr;
            ogCurr = ogCurr->next;
        }
        ogCurr = head;
        while (ogCurr)
        {
            cloneCurr = mp[ogCurr];
            cloneCurr->next = mp[ogCurr->next];
            cloneCurr->arb = mp[ogCurr->arb];
            ogCurr = ogCurr->next;
        }

        return mp[head];
    }
};
