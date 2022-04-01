/****
 * Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). 
 * The left and right pointers in nodes are to be used as previous and next 
 * pointers respectively in converted DLL. The order of nodes in 
 * DLL must be the same as in Inorder for the given Binary Tree. 
 * The first node of Inorder traversal (leftmost node in BT) must be the 
 * head node of the DLL. 
 ****/
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode*left,*right;
    int data;
    TreeNode(int x){
        left = right = nullptr;
        data = x;
    }
};
class Node{
    public:
    Node*prev;
    Node*next;
    int data;
    Node(int x)
    {
        prev = next = nullptr;
        data = x; 
    }
};
class DLL{
    private:
    Node*head,*tail;
    public:
    DLL(){
        head = tail = nullptr;
    }
    void insert(int x){
        Node*newNode = new Node(x);
        if(!head){
            head = newNode;
            tail = head;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void print(){
        Node*curr = head;
        while(curr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
    }
};
void inorder(TreeNode*root){
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void flattenBT(TreeNode*root,DLL **a){
    if(!root){
        return;
    }
    flattenBT(root->left,a);
    (*a)->insert(root->data);
    flattenBT(root->right, a);
}
// Inplace Conversion - without creating additional DLL

TreeNode*convertToDLLHelper(TreeNode*root){
    if(!root){
        return nullptr;
    }

    if(root->left){
        TreeNode*left = convertToDLLHelper(root->left);

        while(left->right){
            left = left->right;
        }
        left->right = root;
        root->left = left;
    }
    if(root->right){
        TreeNode*right = convertToDLLHelper(root->right);

        while(right->left){
            right = right->left;
        }
        right->left = root;
        root->right = right;
    }
    return root;
}
TreeNode*convertToDLL(TreeNode*root){
    if(root){
        root = convertToDLLHelper(root);

        while(root->left){
            root = root->left;
        }
    }
    return root;
}
void printFlattenTree(TreeNode*root){
    while(root){
        cout<<root->data<<" ";
        root = root->right;
    }
}
int main(){
    DLL *a = new DLL();
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(12);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(25);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(36);
    inorder(root);
    cout<<endl;
    root = convertToDLL(root);
    printFlattenTree(root);
    // flattenBT(root,&a);
    // a->print();
    return 0;
}