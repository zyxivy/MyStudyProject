//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

#include "Header.h";
ListNode* Solution::deleteDuplicatesII(ListNode* head) {
    ListNode* p1 = head;
    if (head) {
        ListNode* p2 = head;
        while (p2->next) {
            if (p2->val != p2->next->val) {
                p1->next = p2->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            else {
                p2 = p2->next;
            }
        }
        p1->next = nullptr;
    }
    return head;
}