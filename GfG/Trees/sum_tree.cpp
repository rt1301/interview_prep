/****
 * Given a Binary Tree. Return 1 if, for every node X in the tree other 
 * than the leaves, its value is equal to the sum of its left subtree's 
 * value and its right subtree's value. Else return 0.
 ****/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return false;
    }
    bool isSumTree(Node *root)
    {
        // Your code here
        if (!root || isLeaf(root))
            return true;
        int ls, rs;
        if (isSumTree(root->left) && isSumTree(root->right))
        {
            if (!root->left)
                ls = 0;
            else if (isLeaf(root->left))
            {
                ls = root->left->data;
            }
            else
            {
                ls = 2 * (root->left->data);
            }
            if (!root->right)
                rs = 0;
            else if (isLeaf(root->right))
            {
                rs = root->right->data;
            }
            else
            {
                rs = 2 * (root->right->data);
            }

            return (root->data == ls + rs);
        }
        return false;
    }
};