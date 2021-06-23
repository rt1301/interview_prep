struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int getLength(ListNode *h){
        ListNode *curr = h;
        int size = 0;
        while(curr){
            size++;
            curr = curr->next;
        }
        return size;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*curr = head;
        int l = getLength(curr);
        int end = l-k;
        ListNode *kthNode = nullptr;
        int count = 0;
        while(curr && count<k-1){
            curr = curr->next;
            count++;
        }
        kthNode = curr;
        curr = head;
        count = 0;
        ListNode*endNode = nullptr;
        while(curr && count<end){
            curr = curr->next;
            count++;
        }
        endNode = curr;
        int data = kthNode->val;
        kthNode->val = endNode->val;
        endNode->val = data;
        return head;
    }
};