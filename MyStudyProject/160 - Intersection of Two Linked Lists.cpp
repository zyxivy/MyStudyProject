//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//
//A:          a1 → a2
//    ↘
//    c1 → c2 → c3
//    ↗
//    B : b1 → b2 → b3
//    begin to intersect at node c1.
//
//
//    Notes :
//
//    If the two linked lists have no intersection at all, return null.
//    The linked lists must retain their original structure after the function returns.
//    You may assume there are no cycles anywhere in the entire linked structure.
//    Your code should preferably run in O(n) time and use only O(1) memory.

#include "Header.h";
ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* pA = headA;
    ListNode* pB = headB;
    int stepA = 0;
    int stepB = 0;

    if (!headA || !headB) {
        return NULL;
    }

    //find if there's intercection
    while (pA->next) {
        stepA++;
        pA = pA->next;
    }
    while (pB->next) {
        stepB++;
        pB = pB->next;
    }

    if (pA != pB) {
        return NULL;
    }

    //make smaller one a circle
    ListNode* head;
    if (stepA < stepB) {
        pA->next = headA;
        head = headB;
    }
    else {
        pB->next = headB;
        head = headA;
    }

    //slow fast find intercetion
    ListNode* slow = head;
    ListNode* fast = head;

    fast = fast->next->next;
    slow = slow->next;
    while (slow != fast) {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = head;
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }

    if (stepA < stepB) {
        pA->next = NULL;
    }
    else {
        pB->next = NULL;
    }
    return fast;
}