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

void printAncestors(Node *root, int target){
    if(!root){
        return;
    }

    stack<Node*>st;

    while(1){
        // first Traverse the left subtree and check for
        // Target Node
        while (root && root->data != target)
        {
            st.push(root);
            root = root->left;
        }
        // If the target node is found in left ST, then print
        // Contents of stack
        if(root && root->data == target){
            break;
        }
        // if right subtree of node in stack is null
        // remove it since it is of no use to us
        if(st.top()->right == nullptr){
            root = st.top();
            st.pop();
            // IF the popped node is right child of top of stack
            // Remove the top node as well
            while(!st.empty() && st.top()->right == root){
                root = st.top();
                st.pop();
            }
        }

        if(st.empty()){
            root = nullptr;
        }else{
            root = st.top()->right;
        }
        
    }

    while (!st.empty())
    {
        cout<<st.top()->data<<" ";
        st.pop();
    }
    
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->left = new Node(10);

    cout << "Following are all keys and their ancestors" << endl;
    for (int key = 1; key <= 10; key++)
    {
        cout << key << ":"
             << " ";
        printAncestors(root, key);
        cout << endl;
    }

    return 0;
}