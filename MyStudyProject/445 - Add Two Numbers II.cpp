//You are given two non - empty linked lists representing two non - negative integers.The most significant digit comes first and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Follow up :
//What if you cannot modify the input lists ? In other words, reversing the lists is not allowed.
//
//Example :
//
//	Input : (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 8 -> 0 -> 7

#include "Header.h";
ListNode* Solution::addTwoNumbers445(ListNode* l1, ListNode* l2) {
	vector<int> st1, st2;
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	while (p1) {
		st1.push_back(p1->val);
		p1 = p1->next;
	}
	while (p2) {
		st2.push_back(p2->val);
		p2 = p2->next;
	}
	int sum = 0;
	ListNode* node = new ListNode(0);
	while (!st1.empty() || !st2.empty()) {
		if (!st1.empty()) {
			sum += st1.back();
			st1.pop_back();
		}
		if (!st2.empty()) {
			sum += st2.back();
			st2.pop_back();
		}
		node->val = sum % 10;
		ListNode* cur = new ListNode(sum / 10);
		cur->next = node;
		node = cur;
		sum /= 10;
		st1.pop_back();
		st2.pop_back();
	}
	return node->val == 0 ? node->next : node;
}
