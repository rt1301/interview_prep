/****
 * Given a Binary Tree, find the maximum sum path from a leaf to root. 
 * For example, in the following tree, there are three leaf to 
 * root paths 8->-2->10, -4->-2->10 and 7->10. The sums of these three paths 
 * are 16, 4 and 17 respectively. The maximum of them is 17 and 
 * the path for maximum is 7->10.
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

int solve(Node*root, int &res){
    // Base Conditions
    if(!root){
        return 0;
    }

    // Hypothesis
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    
    // Inductions
    int temp = max(l,r) + root->data;
    if(root->left == nullptr && root->right == nullptr){
        temp = max(temp,root->data);
    }
    int ans = max(temp,l+r+root->data);
    res = max(res,ans);
    return temp;
}
bool printPath(Node *root, Node*target_leaf){
    if(!root){
        return false;
    }
    if(root == target_leaf || printPath(root->left,target_leaf) || printPath(root->right, target_leaf)){
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
void getTargetLeaf(Node*root, Node**target_leaf, int &maxSum, int currSum){
    if(!root){
        return;
    }
    currSum = currSum + root->data;

    if(root->left == nullptr && root->right == nullptr){
        if(currSum>maxSum){
            maxSum = currSum;
            *target_leaf = root;
        }
    }

    getTargetLeaf(root->left,target_leaf,maxSum,currSum);
    getTargetLeaf(root->right,target_leaf,maxSum,currSum);

}
int maxSumPath(Node *root){
    if(!root){
        return 0;
    }
    int max_sum_leaf = INT_MIN;
    Node*target_leaf = nullptr;
    getTargetLeaf(root,&target_leaf,max_sum_leaf,0);
    printPath(root,target_leaf);
    return max_sum_leaf;
}
int main(){
    Node *root = NULL;

    /* Constructing tree given in the above figure */
    root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);

    cout << "Following are the nodes on the maximum "
            "sum path \n";
    int res = maxSumPath(root);
    cout << "\nSum of the nodes is " << res;
    return 0;
}