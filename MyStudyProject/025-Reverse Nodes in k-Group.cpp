//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5

#include "Header.h";

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
	if (!head || !head->next) {
		return head;
	}

	ListNode* pK = head;
	head = nullptr;
	ListNode* pPrev = nullptr;
	while (pK) {
		int count = k;
		ListNode* p0 = pK;
		ListNode* phead = pK;

		while (pK && count > 0) {
			pK = pK->next;
			count--;
		}
		if (count > 0) {
			if (!head) {
				head = phead;
			}
			break;
		}
		else {
			ListNode* p = phead->next;
			while (p && p != pK) {
				ListNode* pnext = p->next;
				p->next = phead;
				p0->next = pnext;
				phead = p;
				if (p && pnext) {
					p = pnext;
				}
				else {
					break;
				}
			}
			if (!head) {
				head = phead;
			}
			if (pPrev)
			{
				pPrev->next = phead;
				pPrev = p0;
			}
			else {
				pPrev = p0;
			}
		}
	}
	return head;
}