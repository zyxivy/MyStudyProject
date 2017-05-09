//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

#include "Header.h";
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* pGuard = new ListNode(-1);
    pGuard->next = head;
    ListNode* p1 = pGuard;
    ListNode* p2 = head;
    bool flag = false;
    if (head) {
        while (p2->next) {
            if (p2->val == p2->next->val) {
                flag = true;
                p2 = p2->next;
            }
            else {
                if (flag == true) {
                    p1->next = p2->next;
                    flag = false;
                    p2 = p2->next;
                }
                else {
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
        }
        if (flag)
            p1->next = nullptr;
    }
    return pGuard->next;
}