/****
 * Construct a binary tree from a string consisting of parenthesis and integers. 
 * The whole input represents a binary tree. It contains an integer followed by zero, 
 * one or two pairs of parenthesis. The integer represents the root’s value 
 * and a pair of parenthesis contains a child binary tree with the same structure.
 * Always start to construct the left child node of the parent first if it exists.
 * PS - https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
 ****/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int findIndex(string str, int si, int ei)
{
    if (si > ei)
    {
        return -1;
    }

    stack<char> s;

    for (int i = si; i <= ei; i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}

Node *solve(string str, int si, int ei)
{
    if (si > ei)
        return nullptr;
    int val = str[si] - '0';
    Node *root = new Node(val);
    int index = -1;

    if (si + 1 <= ei && str[si + 1] == '(')
    {
        index = findIndex(str, si + 1, ei);
    }

    if (index != -1)
    {
        root->left = solve(str, si + 2, index - 1);
        root->right = solve(str, index + 2, ei - 1);
    }
    return root;
}

int main()
{
    string str;
    cin >> str;
    Node *root = solve(str, 0, str.length() - 1);
    preorder(root);
    return 0;
}