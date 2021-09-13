/****
 * Given a Binary Search Tree (BST), convert it to a Binary Tree such 
 * that every key of the original BST is changed to key plus sum of all 
 * greater keys in BST. 
 ****/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left,*right;
    int data;
    Node(int val){
        left = right = nullptr;
        data = val;
    }
};

void convert(Node*root, int *sum){
    if(!root){
        return;
    }
    convert(root->right,sum);
    *sum = *sum + root->data;
    root->data = *sum;
    convert(root->left,sum);
}
void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    Node*root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(13);
    inorder(root);
    int sum = 0;
    convert(root,&sum);
    cout<<endl;
    inorder(root);
    return 0;
}