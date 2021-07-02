/****
 * Given a binary tree, where every node value is a Digit from 1-9 .
 * Find the sum of all the numbers which are formed from root to leaf paths.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        this->data = val;
        this->left=this->right=nullptr;
    }
};

int leafSumUtil(Node*root,int sum){
    if(root == NULL){
        return 0;
    }
    sum = 10*sum + root->data;
    if(root->left == NULL && root->right == NULL){
        return sum;
    }
    return leafSumUtil(root->left,sum) + leafSumUtil(root->right,sum);
}

int leafSum(Node*root){
    return leafSumUtil(root,0);
}

int main(){
    Node *root = new Node(6); 
    root->left = new Node(3); 
    root->right = new Node(5); 
    root->left->left = new Node(2); 
    root->left->right = new Node(5); 
    root->right->right = new Node(4); 
    root->left->right->left = new Node(7); 
    root->left->right->right = new Node(4); 
    cout<<"Sum of all paths is "<<leafSum(root); 
    return 0; 
}