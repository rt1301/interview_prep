/****
 * Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.
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

void helper(Node*root, Node**first, Node**last, Node**mid, Node**prev){
    if(!root){
        return;
    }
    helper(root->left,first,last,mid,prev);
    // current node is smaller than previous node
    if(*prev && root->data < ((*prev)->data)){
        if(!*first){
            // violating rule for first time
            // mark these two nodes as first and prev
            *first = *prev;
            *mid = root;
        }else{
            *last = root;
        }
    }

    *prev = root;

    helper(root->right,first,last,mid,prev);
}

void fixBST(Node*root){
    Node*first,*last,*mid,*prev;
    first=last=mid=prev = nullptr;

    helper(root,&first,&last,&mid,&prev);

    if(first && last){
        swap((first->data),(last->data));
    }else if(first && mid){
        swap((first->data),(mid->data));
    }
}

void printTree(Node*root){
    if(!root){
        return;
    }
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){
    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    cout << "Inorder Traversal of the original tree \n";
    printTree(root);

    fixBST(root);

    cout << "\nInorder Traversal of the fixed tree \n";
    printTree(root);

    return 0;
}