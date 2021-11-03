//Problem Link -> https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Approach :-
// * As we solve ZERO SUM problem using hashmap, similarly we can record all our sum as key and value as the node till where that sum is calculated.
// * Whenever we encounter a sum which is already present in our map, we will remove all the nodes from the next of the mapped node till the current node
//   ans simultanoeusly erase the key which has some from the curr sum to the curr node

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* helper = new ListNode();
        helper->next = head;
        unordered_map<int, ListNode*> m;
        m[0] = helper;
        ListNode* curr = head;
        int sum = 0;
        
        while(curr){
            sum += curr->val;
            if(m.find(sum) != m.end()){
                curr = m[sum]->next;
                int curr_sum = sum + curr->val;
                while(curr_sum != sum){
                    m.erase(curr_sum);
                    curr = curr->next;
                    curr_sum += curr->val;
                }
                m[sum]->next = curr->next;
            }
            else{
                m[sum] = curr;
            }
            curr = curr->next;
        }
        
        return helper->next;
    }
};  