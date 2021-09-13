/****
 * Given a BST and an integer K. Find the Kth Smallest element in the BST.
 * PS - https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Return the Kth smallest element in the given BST
    Node *inorder(Node *root, int &K)
    {
        if (!root)
        {
            return NULL;
        }
        Node *left = inorder(root->left, K);
        if (left)
        {
            return left;
        }

        K--;
        if (K == 0)
        {
            return root;
        }

        return inorder(root->right, K);
    }
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        Node *node = inorder(root, K);
        if (!node)
        {
            return -1;
        }
        else
        {
            return node->data;
        }
    }
};