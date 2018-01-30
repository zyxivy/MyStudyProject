//Given a non - negative number represented as a singly linked list of digits, plus one to the number.
//The digits are stored such that the most significant digit is at the head of the list.
//Example:
//Input:
//1->2->3
//
//Output :
//    1->2->4

#include "Header.h";

//find the most significant digit that all the digits following it are 9
//i.e. find the most siginificant digit != 9.
ListNode* Solution::plusOne(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* i = dummy;
    ListNode* j = dummy;
    while (j->next != nullptr) {
        j = j->next;
        if (j->val != 9) {//Pointer i points to the first node before the tailing 9s,
            i = j;
        }
    }
    if (j->val != 9) {
        j->val++;
    }
    else {
        i->val++;
        i = i->next;
        while (i) {
            i->val = 0;
            i = i->next;
        }
    }
    if (dummy->val == 0) {
        return dummy->next;
    }
    return dummy;
}