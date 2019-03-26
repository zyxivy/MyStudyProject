//You are given two linked lists representing two non - negative numbers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output : 7 -> 0 -> 8

#include "Header.h"


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* l = new ListNode(0);
    ListNode* h = l;
    while (l1 || l2) {
        int v1 = l1 != nullptr ? l1->val : 0;
        int v2 = l2 != nullptr ? l2->val : 0;
        int v = v1 + v2 + carry;
        carry = v / 10;
        v = v % 10;
        ListNode* t = new ListNode(v);
        l->next = t;
        l1 = l1 != nullptr ? l1->next : l1;
        l2 = l2 != nullptr ? l2->next : l2;

        l = l->next;
    }

    if (carry) {
        ListNode* t = new ListNode(carry);
        l->next = t;
    }
    return h->next;
}

//int main()
//{
//    ListNode* l10 = new ListNode(3);
//    ListNode* l11 = new ListNode(5);
//    ListNode* l12 = new ListNode(8);
//
//    ListNode* l20 = new ListNode(7);
//    ListNode* l21 = new ListNode(6);
//    ListNode* l22 = new ListNode(9);
//
//    l10->next = l11;
//    l11->next = l12;
//    l20->next = l21;
//    l21->next = l22;
//    Solution::addTwoNumbers(l10, l20);
//}