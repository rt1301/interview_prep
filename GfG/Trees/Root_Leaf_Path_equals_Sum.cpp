/****
 * Given a binary tree and a number, return true if the tree has a 
 * root-to-leaf path such that adding up all the values 
 * along the path equals the given number. Return false if no such path can be found. 
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

bool isPathSum(Node*root, int sum){
    
    int subSum = 0;
    subSum = sum - root->data;
    bool ans = 0;
    if(!root->left && !root->right && subSum==0){
        return true;
    }
    if(root->left){
        ans = ans || isPathSum(root->left,subSum);
    }
    if(root->right){
        ans = ans || isPathSum(root->right,subSum);
    }
    return ans;
}

int main(){
    int sum = 21;

    /* Constructed binary tree is
                10
            / \
            8 2
        / \ /
        3 5 2
    */
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    if (isPathSum(root, sum))
        cout << "There is a root-to-leaf path with sum " << sum;
    else
        cout << "There is no root-to-leaf path with sum " << sum;

    return 0;
}