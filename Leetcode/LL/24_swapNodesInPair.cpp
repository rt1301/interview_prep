#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode*curr = head;
        ListNode*next = nullptr;
        if(curr){
            next = curr->next;
        }
        while(curr && next){
            swap(curr->val,next->val);
            curr = next->next;
            if(curr){
                next = curr->next;
            }
        }
        return head;
    }
};