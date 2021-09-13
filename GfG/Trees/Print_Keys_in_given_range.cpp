/****
 * Given two values k1 and k2 (where k1 < k2) and a root pointer to a 
 * Binary Search Tree. Print all the keys of the tree in range k1 to k2. 
 * i.e. print all x such that k1<=x<=k2 and x is a key of given BST. 
 * Print all the keys in increasing order. 
 ****/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left,*right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

void printKeys(Node *root, int k1, int k2){
    if(!root){
        return;
    }
    printKeys(root->left,k1,k2);
    if (root->data > k2)
    {
        return;
    }
    if(root->data>=k1 && root->data<=k2){
        cout<<root->data<<" ";
    }
    printKeys(root->right,k1,k2);
}

int main(){
    Node *root = new Node(20);
    int k1 = 10, k2 = 25;
    root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);

    printKeys(root,k1,k2);

    return 0;
}