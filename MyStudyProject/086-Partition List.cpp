//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

#include "Header.h";
ListNode* Solution::partitionList(ListNode* head, int x) {
    ListNode* pG = new ListNode(INT_MIN);
    pG->next = head;
    ListNode* i = pG;
    ListNode* j = head;

    //make i->next point to the first node greater than x;
    while (i->next) {
        if (i->next->val < x) {
            i = i->next;
        }
        else {
            break;
        }
    }
    if (i->next == nullptr) {
        return head;
    }
    j = i->next;
    while (j&&j->next) {
        if (j->next->val < x) {
            ListNode*tmp = j->next->next;
            j->next->next = i->next;
            i->next = j->next;
            j->next = tmp;

            //j = tmp;
            i = i->next;
        }
        else {
            j = j->next;
        }
    }
    return pG->next;
}