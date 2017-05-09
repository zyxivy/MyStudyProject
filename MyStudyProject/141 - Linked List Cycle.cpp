//Given a linked list, determine if it has a cycle in it.
//Follow up :
//Can you solve it without using extra space ?

#include "Header.h";

bool Solution::hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}