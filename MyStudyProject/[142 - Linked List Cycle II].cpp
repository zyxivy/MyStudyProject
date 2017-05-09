//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//Note: Do not modify the linked list.
//    Follow up :
//Can you solve it without using extra space ?


//http://fisherlei.blogspot.com/2013/11/leetcode-linked-list-cycle-ii-solution.html
#include "Header.h";
ListNode* Solution::detectCycle(ListNode *head) {

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL) return NULL;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}