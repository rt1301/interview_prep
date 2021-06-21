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
    int len(ListNode *h){
        ListNode *ref = h;
        int size = 0;
        while(ref){
            ref = ref->next;
            size++;
        }
        return size;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || len(head)<k) return head;
        ListNode*next;
        ListNode*curr = head;
        ListNode*prev = nullptr;
        int count = 0;
        while(count<k && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next != nullptr){
            head->next = reverseKGroup(next, k);
        }
        
        return prev;
    }
};