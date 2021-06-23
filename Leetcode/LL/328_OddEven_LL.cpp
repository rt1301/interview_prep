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
    ListNode* oddEvenList(ListNode* head) {
        vector<int>odd;
        vector<int>even;
        ListNode*ref = head;
        int i=0;
        while(ref){
            if(i%2 == 0){
                even.push_back(ref->val);
            }else{
                odd.push_back(ref->val);
            }
            ref = ref->next;
            i++;
        }
        ref = head;
        i = 0;
        while(ref && i<even.size()){
            int data = even[i];
            ref->val = data;
            ref = ref->next;
            i++;
        }
        i = 0;
        while(ref && i<odd.size()){
            int data = odd[i];
            ref->val = data;
            ref = ref->next;
            i++;
        }
        return head;
    }
};