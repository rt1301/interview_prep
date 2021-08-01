#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode*next[2];
    TrieNode(){
        next[0] = nullptr;
        next[1] = nullptr;
    }
};
TrieNode* buildTree(TrieNode*root,vector<int>a){
    int n = a.size();
    for(int i=0;i<n;i++){
        TrieNode*curr = root;
        int num = a[i];
        for(int j=31;j>=0;j--){
            int bit = (num>>j)&1;
            if(curr->next[bit] == nullptr){
                curr->next[bit] = new TrieNode();
            }
            curr = curr->next[bit];
        }
    }
    return root;
}
int helper(TrieNode*root, vector<int>a){
    int res = 0;
    int n = a.size();
    for(int i=0;i<n;i++){
        int num = a[i];
        int curr_max = 0;
        for(int j=31;j>=0;j--){
            TrieNode*it = root;
            int bit = ((num>>j)&1)?0:1;
            if(it->next[bit]){
                curr_max<<=1;
                curr_max|=1;
                it = it->next[bit];
            }else{
                curr_max<<=1;
                curr_max|=0;
                it = it->next[bit xor 1];
            }
        }
        res = max(res,curr_max);
    }
    return res;
}
int main(){
    vector<int>a = {3,10,5,15,2};
    TrieNode*root = new TrieNode();
    root = buildTree(root,a);
    int ans = helper(root,a);
    cout<<ans;
    return 0;
}