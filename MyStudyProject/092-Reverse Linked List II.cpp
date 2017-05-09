//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note :
//    Given m, n satisfy the following condition :
//1 ≤ m ≤ n ≤ length of list.

#include "Header.h";
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    ListNode* pGuard = new ListNode(0);
    pGuard->next = head;
    ListNode* nth = pGuard, *preNth = pGuard, *preMth = pGuard, *mth = pGuard;
    if (n <= m) {
        return head;
    }
    int i = 1; 
    while (i != n && preNth) {
        preNth = preNth->next;
        i++;
    }
    if (preNth == nullptr || preNth->next == nullptr) {
        return head;
    }
    nth = preNth->next;

    i = 1;
    while (i != m && preMth) {
        preMth = preMth->next;
        i++;
    }
    if (preMth == nullptr) {
        return head;
    }
    mth = preMth->next;

    ListNode *pre = preMth, *cur = mth;
    i = 0;
    while (i != n - m) {
        ListNode* curNext = cur->next, *preNext = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        curNext->next = preNext;
        i++;
    }
    return pGuard->next;
}