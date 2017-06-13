//Remove all elements from a linked list of integers that have value val.
//Example
//Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//    Return: 1 --> 2 --> 3 --> 4 --> 5

#include "Header.h";
ListNode* Solution::removeElements(ListNode* head, int val) {

    ListNode* newHead = new ListNode(0);
    newHead->next = head;    
    
    ListNode* pre = newHead;
    ListNode* cur = newHead->next;
    while (cur) {
        if (cur->val == val) {
            pre->next = cur->next;
            cur = cur->next;
        }
        else {
            pre = pre->next;
            cur = cur->next;
        }
    }
    return newHead->next;
}