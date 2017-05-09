//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.

#include "Header.h";

ListNode* Solution::swapPairs(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* p1 = head;
	ListNode* p2 = head->next;
	ListNode* p0 = nullptr;
	head = head->next;
	while (p1&& p2) {
		ListNode* p3 = p2 ->next;
		p2->next = p1;
		p1 -> next = p3;
		if (p0) {
			p0->next = p2;
		}
		if (p3 && p3->next) {
			p0 = p1;
			p1 = p3;
			p2 = p3->next;
		}
		else {
			break;
		}
	}
	return head;
}