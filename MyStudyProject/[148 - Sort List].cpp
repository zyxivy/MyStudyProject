//Sort a linked list in O(n log n) time using constant space complexity

#include "Header.h";

void split(ListNode* head, ListNode** left, ListNode** right) {

    ListNode* pSlow = head;
    ListNode* pFast = head;

    if (!head || !head->next) {
        *left = head;
        *right = NULL;
        return;
    }
    while (pFast && pFast->next) {
        pFast = pFast->next->next;
        if (!pFast)
            break;

        pSlow = pSlow->next;
    }
    *left =  head;
    *right = pSlow->next;
    pSlow->next = NULL;
}

ListNode* mergeList(ListNode* left, ListNode* right) {
    ListNode* phead = new ListNode(INT_MIN);
    ListNode* cur = phead;
    while (left && right) {
        if (left->val <= right->val) {
            cur->next = left;
            left = left->next;
        }
        else {
            cur->next = right;
            right = right->next;
        }
        cur = cur->next;
    }
    if (left) {
        cur->next = left;
    }
    if (right) {
        cur->next = right;
    }
    return phead->next;
}

void mergeSort(ListNode** headRef) {
    ListNode* head = *headRef;
    ListNode* left;
    ListNode* right;

    if (!head || !head->next) {
        return;
    }
    split(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = mergeList(left, right);
}

ListNode* Solution::sortList(ListNode* head) {
    mergeSort(&head);
    return head;
}