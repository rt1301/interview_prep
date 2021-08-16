#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*left,*right;
    int data;
    Node(int x){
        left=right=nullptr;
        data = x;
    }
};

void printLeaves(Node *root){
    if(!root){
        return;
    }
    printLeaves(root->left);
    if(root->left == nullptr && root->right == nullptr){
        cout<<root->data<<" ";
    }
    printLeaves(root->right);
}
void printLeftBoundary(Node *root){
    if(!root){
        return;
    }
    if(root->left){
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}
void printRightBoundary(Node *root){
    if(!root){
        return;
    }
    if(root->right){
        cout<<root->data<<" ";
        printRightBoundary(root->right);
    }
    else if(root->left){
        cout<<root->data<<" ";
        printRightBoundary(root->left);
    }
}
void boundaryTraversal(Node *root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    printLeftBoundary(root->left);

    printLeaves(root->left);
    printLeaves(root->right);

    printRightBoundary(root->right);
}
int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    boundaryTraversal(root);
    return 0;
}