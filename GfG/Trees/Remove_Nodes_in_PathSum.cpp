/****
 * Given a binary tree, a complete path is defined as a path from root to a leaf. 
 * The sum of all nodes on that path is defined as the sum of that path. 
 * Given a number K, you have to remove (prune the tree) all nodes 
 * which don’t lie in any path with sum>=k. 
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
Node* helper(Node*root, int k, int *sum){
    if(!root){
        return nullptr;
    }
    int leftSum = root->data  + *sum;
    int rightSum = leftSum;

    root->left = helper(root->left,k,&leftSum);
    root->right = helper(root->right,k,&rightSum);

    *sum = max(leftSum,rightSum);

    if(*sum < k){
        delete root;
        root = nullptr;
    }

    return root;

}
Node* removeNodes(Node *root, int k){
    int sum = 0;
    return helper(root,k,&sum);
}
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        cout << " " << root->data;
        print(root->right);
    }
}
int main(){
    int k = 45;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(12);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    root->left->left->right->left = new Node(13);
    root->left->left->right->right = new Node(14);
    root->left->left->right->right->left = new Node(15);

    cout << "Tree before truncation\n";
    print(root);

    root = removeNodes(root, k); // k is 45

    cout << "\n\nTree after truncation\n";
    print(root);

    return 0;
}