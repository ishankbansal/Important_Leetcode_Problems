// Problem link -> https://leetcode.com/problems/reverse-linked-list-ii/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;
        
        while(1){
            cnt++;
            if(cnt == left){
                ListNode* inner_curr = curr;
                ListNode* inner_prev = NULL;
                ListNode* nextptr;
                
                while(cnt <= right){
                    nextptr = inner_curr->next;
                    inner_curr->next = inner_prev;
                    inner_prev = inner_curr;
                    inner_curr = nextptr;
                    cnt++;
                }
                if(prev == NULL){
                    head = inner_prev;
                }
                else{
                    prev->next = inner_prev;
                }
                curr->next = inner_curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};