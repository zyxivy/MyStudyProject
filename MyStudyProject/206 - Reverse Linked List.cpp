//Reverse a singly linked list.
//click to show more hints.
//Hint:
//A linked list can be reversed either iteratively or recursively.Could you implement both ?

#include "Header.h"
ListNode* Solution::reverseList(ListNode* head) {
    if (!head) {
        return NULL;
    }
    
    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* nxt = cur->next;
    while (cur) {

        cur->next = pre;
        pre = cur;
        cur = nxt;
        if (nxt) {
            nxt = nxt->next;
        }
    }
    return pre;
}