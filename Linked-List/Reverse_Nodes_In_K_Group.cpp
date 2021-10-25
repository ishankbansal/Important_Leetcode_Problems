// Problem Link -> https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int n = 0;
        while(curr){
            curr = curr->next;
            n++;
        }
        curr = head;
        ListNode dummy(0);
        ListNode* prev = &dummy;
        ListNode* nextPtr = head;
        
        while(n >= k){
            ListNode* help = prev;
            ListNode* x = curr;
            for(int i = 1; i <= k; i++){
                nextPtr = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextPtr;
            }
            help->next = prev;
            prev = x;
            x->next = curr;
            n -= k;
        }
        return dummy.next;
    }
};