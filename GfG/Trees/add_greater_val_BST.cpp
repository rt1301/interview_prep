/****
 * Given a Binary Search Tree (BST), modify it so that 
 * all greater values in the given BST are added to every node.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left,*right;
    int data;
    Node(int x){
        left = right = nullptr;
        data = x;
    }
};

void dfs(Node *root, int &sum){
    if(!root){
        return;
    }
    dfs(root->right,sum);
    root->data+=sum;
    sum = root->data;
    dfs(root->left,sum);
}
void printTree(Node *root)
{
    if (!root)
    {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}
int main(){
    Node*root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    printTree(root);
    cout<<endl;
    int sum = 0;
    dfs(root,sum);
    printTree(root);
    return 0;
}