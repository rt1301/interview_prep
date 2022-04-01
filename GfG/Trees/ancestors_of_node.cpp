/****
 * Given a Binary Tree and a key, write a function that prints all the 
 * ancestors of the key in the given binary tree. 
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

bool printAncestors(Node*root, int target){
    if(!root){
        return false;
    }

    if(root->data == target){
        return true;
    }

    if(printAncestors(root->left,target) || printAncestors(root->right,target)){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);

    printAncestors(root, 7);

    return 0;
}