// Problem link -> https://leetcode.com/problems/intersection-of-two-linked-lists/
// Approach :-
// * Simultaneously we traverse over the both linked list, and whenver any of the pointer reach NULL we will initialse it to the head of other linked list
// * whenever both the pointers point to the same node we return that node

class Solution{
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
		if(headA == NULL || headB == NULL){
			return NULL;
		}

		ListNode* ptr1 = headA, *ptr2 = headB;

		while(ptr1 != NULL && ptr2 != NULL && ptr1 != ptr2){
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;

			if(ptr1 == ptr2){
				return ptr1;
			}

			if(ptr1 == NULL){
				ptr1 = headB;
			}
			if(ptr2 == NULL){
				ptr2 = headA;
			}
		}

		return ptr1;
	}
};