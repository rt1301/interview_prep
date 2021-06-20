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
    bool isPalindrome(ListNode* head) {
        stack<int>s;
        ListNode*ref = head;
        while(ref != nullptr){
            s.push(ref->val);
            ref = ref->next;
        }
        while(head != nullptr){
            int i = s.top();
            s.pop();
            if(i != head->val){
                return false;
            }
            head = head->next;
        }
        return true;
        
    }
};