//Given a list, rotate the list to the right by k places, where k is non - negative.
//
//For example :
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

#include "Header.h";

ListNode* Solution::rotateRight(ListNode* head, int k) {
    int len = 0;
    ListNode* p = head;
    while (p != nullptr) {
        p = p->next;
        len++;
    }
    if (len > 0) {
        k = k%len;
        ListNode* p1 = head;
        ListNode* p2 = head;
        int i = k;
        while (k--) {
            p2 = p2->next;
        }
        while (p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = head;
        head = p1->next;
        p1->next = nullptr;
    }
    return head;
}