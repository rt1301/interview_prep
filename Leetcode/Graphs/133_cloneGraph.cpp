#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* dfs(Node*root){
        if(mp.find(root) != mp.end()) return mp[root];
        Node *copy = new Node(root->val);
        mp[root] = copy;
        for(auto it:root->neighbors){
            copy->neighbors.push_back(dfs(it));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        dfs(node);
        return mp[node];
    }
};