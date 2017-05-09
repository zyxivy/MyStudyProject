//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//    Given n will always be valid.
//    Try to do this in one pass.

#include "Header.h";

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    ListNode* pHead = head;
    if (head != NULL && n>0)
    {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next != NULL)
        {
            if (n > 0)
            {
                p2 = p2->next;
                n--;
                continue;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        if (n > 1)
        {
            return pHead;
        }
        else if (n == 1)
        {
            pHead = head->next;
        }
        else
        {
            p1->next = p1->next->next;
        }

    }

    return pHead;
}