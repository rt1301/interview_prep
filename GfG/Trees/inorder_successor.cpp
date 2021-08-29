/****
 * In Binary Tree, Inorder successor of a node is the next node in Inorder 
 * traversal of the Binary Tree. Inorder Successor is NULL for the last node 
 * in Inorder traversal. 
 * In Binary Search Tree, Inorder Successor of an input node can also be defined 
 * as the node with the smallest key greater than the key of the input node. 
 * So, it is sometimes important to find next node in sorted order.
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
vector<int>traverseList;
void inorder(Node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    traverseList.push_back(root->data);
    inorder(root->right);
}
int binarySearch(vector<int>v, int x){
    int n = v.size();
    int l = 0;
    int r = n-1;
    int m = 0;
    while (l<=r)
    {
        m = l + (r-l)/2;
        if(v[m] == x){
            return m;
        }
        if(v[m] <= x){
            l = m+1;
        }else{
            r = m-1;
        }
    }
    return -1;
}
// Approach 2 
Node*minVal(Node *root){
    Node*curr = root;
    while(curr->left){
        curr = curr->left;
    }
    return curr->left;
}
Node*inorderSuccessor(Node *root, Node*node){
    if(node->right){
        return minVal(node->right);
    }
    Node*succ;
    while(root){
        if(node->data < root->data){
            succ = root;
            root = root->left;
        }else if(node->data > root->data){
            root = root->right;
        }else{
            break;
        }
    }
    return succ;
}
Node *insert(Node *root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new Node(value);
    }

    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}
int main(){
    Node*root;
    root = new Node(20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    // Approach 1
    // inorder(root);
    // int x = 10;
    // int idx = binarySearch(traverseList,x);
    // if(idx != -1 && idx<(traverseList.size()-1)){
    //     cout<<traverseList[idx+1];
    // }else{
    //     cout<<"No inorder successor is found";
    // }

    // Approach 2
    Node *temp = root->left->right->right;
    Node*succ = inorderSuccessor(root,temp);
    if (succ != NULL)
        cout << "Inorder Successor of "
             << temp->data << " is " << succ->data;
    else
        cout << "\n Inorder Successor doesn't exit";
    return 0;
}