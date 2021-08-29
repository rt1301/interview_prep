#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left,*right;
    int data;
    Node(int x){
        this->left = this->right = nullptr;
        this->data = x;
    }
};
void dfs(Node *root){
    if(!root){
        return;
    }
    Node*left = root->left;
    Node *newNode = new Node(root->data);
    root->left = newNode;
    newNode->left = left;
    dfs(root->left->left);
    dfs(root->right);
}
void printTree(Node*root){
    if (!root)
    {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    printTree(root);
    cout<<endl;
    dfs(root);
    printTree(root);
    return 0;
}