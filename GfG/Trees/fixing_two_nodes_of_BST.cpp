/****
 * You are given the root of a binary search tree(BST), where exactly 
 * two nodes were swapped by mistake. Fix (or correct) the BST by swapping 
 * them back. Do not change the structure of the tree.
 * PS - https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(Node *root, Node **first, Node **last, Node **prev, Node **mid)
    {
        if (root)
        {
            helper(root->left, first, last, prev, mid);
            if (*prev && (*prev)->data > root->data)
            {
                if (!(*first))
                {
                    *first = *prev;
                    *mid = root;
                }
                else
                {
                    *last = root;
                }
            }
            *prev = root;
            helper(root->right, first, last, prev, mid);
        }
    }

    void correctBST(struct Node *root)
    {
        // add code here.
        Node *first, *last, *prev, *mid;
        first = last = prev = mid = nullptr;
        helper(root, &first, &last, &prev, &mid);
        if (first && last)
        {
            swap(first->data, last->data);
        }
        else if (first && mid)
        {
            swap(first->data, mid->data);
        }
    }
};