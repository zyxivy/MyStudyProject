//You are given two linked lists representing two non - negative numbers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output : 7 -> 0 -> 8

#include "Header.h"


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ret = new ListNode(-1);
        ListNode* head = ret;

        while (l1 || l2) {
            int v1 = l1 != NULL ? l1->val : 0;
            int v2 = l2 != NULL ? l2->val : 0;

            ListNode* tmp = new ListNode((v1 + v2 + carry) % 10);
            tmp->val = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;
            l1 = l1 != NULL ? l1->next : l1;;
            l2 = l2 != NULL ? l2->next : l2;;
            ret->next = tmp;
            ret = ret->next;
        }

        if (carry > 0) {
            ListNode* tmp = new ListNode(carry);
            ret->next = tmp;
        }
        head = head->next;
        return head;
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