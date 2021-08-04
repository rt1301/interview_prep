/****
 * Given a binary tree, connect the nodes that are at same level. 
 * You'll be given an addition nextRight pointer for the same.
 * Initially, all the nextRight pointers point to garbage values. 
 * Your function should set these pointers to point next right for each node.
 ****/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node *nextRight; // This has garbage value in input trees
};
class Solution
{
public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        // Your Code Here
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            Node *x = NULL;
            for (int i = 0; i < n; i++)
            {
                if (x != NULL)
                {
                    x->nextRight = q.front();
                }
                x = q.front();
                q.pop();
                if (x->left)
                {
                    q.push(x->left);
                }
                if (x->right)
                {
                    q.push(x->right);
                }
            }
            x->nextRight = nullptr;
        }
    }
};