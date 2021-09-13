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

Node *removeKeys(Node*root, int min, int max){
    // return root;
    if (root == NULL)
        return NULL;
        
    root->left = removeKeys(root->left, min, max);
    root->right = removeKeys(root->right, min, max);

    // Now fix the root.  There are 2 possible cases for root
    // 1.a) Root's key is smaller than min value (root is not in range)
    if (root->data < min)
    {
        Node *rChild = root->right;
        delete root;
        return rChild;
    }
    // 1.b) Root's key is greater than max value (root is not in range)
    if (root->data > max)
    {
        Node *lChild = root->left;
        delete root;
        return lChild;
    }
    // 2. Root is in range
    return root;
}
Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        Node*node = new Node(key);
        return node;
    }

    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
void inorderTraversal(Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
int main(){
    Node *root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);

    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);
    Node *newRoot = nullptr;
    cout<<endl;
    newRoot = removeKeys(root, -10, 13);

    cout << "\nInorder traversal of the modified tree is: ";
    inorderTraversal(newRoot);

    return 0;
}