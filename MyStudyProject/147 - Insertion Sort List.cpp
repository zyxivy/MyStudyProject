//Sort a linked list using insertion sort.

#include "Header.h";

ListNode* Solution::insertionSortList(ListNode* head) {
    ListNode* phead = new ListNode(INT_MIN);
    phead->next = head;

    if (!head || !head->next) {
        return head;
    }

    ListNode* p1 = head;
    ListNode* p2 = phead;

    while (p2) {
        while (p2&& p2->next && p2->val <= p2->next->val) {
            p2 = p2->next;
        }
        if (!p2->next)
            break;
        p1 = phead;
        ListNode* cur = p2->next;
        ListNode* nxt2 = p2->next->next;
        while (p1&& p1->next && p1->next->val <= cur->val) {
            p1 = p1->next;
        }
        ListNode* nxt1 = p1->next;
        p1->next = cur;
        cur->next = nxt1;

        p2->next = nxt2;
       // p2 = nxt2;
    }

    return phead->next;
}
