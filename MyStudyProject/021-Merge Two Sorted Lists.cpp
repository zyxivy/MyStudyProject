//Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.

#include "Header.h";

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr) {
        return l1;
    }
    if (l2 == l1) {
        return l1;
    }
    ListNode* p = l1->val <= l2->val ? l1 : l2;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            if (l1->next == nullptr) {
                l1->next = l2;
                l2 = l1;
                break;
            }
            if (l1->next->val >= l2->val) {
                ListNode* n = l2->next;
                l2->next = l1->next;
                l1->next = l2;
                l2 = n;
            }
            else {
                l1 = l1->next;
            }
        }
        else{
            if (l2->next == nullptr) {
                l2->next = l1;
                l1 = l2;
                break;
            }
            if (l2->next->val >= l1->val) {
                ListNode* n = l1->next;
                l1->next = l2->next;
                l2->next = l1;
                l1 = n;
            }
            else {
                l2 = l2->next;
            }
        }
    }
    return p;
}