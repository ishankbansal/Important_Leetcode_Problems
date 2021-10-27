//Problem Link -> https://leetcode.com/problems/copy-list-with-random-pointer/
// Approach :-
// * First We attach a new node to the next of the current node having same value as current and next of this new node will point to the current->next
// * Now the random pointer of every node have a node corresponding to it and we will attach to that node;
// * at last we will extract our clone linked list

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        
        Node* temp1 = head, *temp2;
        
        for(; temp1 != NULL; temp1 = temp1->next->next){
            temp2 = new Node(temp1->val);
            temp2->next = temp1->next;
            temp1->next = temp2;
        }
        
        Node* newHead = head->next;
        
        for(temp1 = head; temp1 != NULL; temp1 = temp1->next->next){
            if(temp1->random != NULL){
                temp1->next->random = temp1->random->next;
            }
        }
        
        for(temp1 = head; temp1 != NULL; temp1 = temp1->next){
            temp2 = temp1->next;
            temp1->next = temp2->next;
            if(temp2->next != NULL){
                temp2->next = temp2->next->next;
            }
        }
        
        return newHead;
    }
};