//Given a singly linked list, determine if it is a palindrome.
//Follow up :
//Could you do it in O(n) time and O(1) space ?

#include "Header.h";
bool Solution::isPalindrome(ListNode* head) {
    ListNode* pHead = head;
    ListNode* pSlow = head;
    ListNode* pFast = head;
    bool isOdd = false;
    if (!head) {
        return false;
    }
    if (!head->next) {
        return true;
    }
    if (!head->next->next) {
        return head->val == head->next->val;
    }
    while (pFast && pFast->next) {
        pSlow = pSlow->next;
        pFast = pFast->next->next;
    }
    if (pFast) {
        isOdd = true;
    }
    ListNode* pMid = pSlow;

    ListNode* pre = pHead;
    ListNode* cur = pHead->next;
    ListNode* nxt = cur->next;
    while (cur->next && cur != pMid) {
        pre->next = nxt;
        cur->next = pHead;

        pHead = cur;
        cur = nxt;
        nxt = cur->next;
    }

    pSlow = pHead;
    pMid = isOdd ? pMid->next : pMid;
    while (pMid) {
        if (pSlow->val != pMid->val) {
            return false;
        }
        pMid = pMid->next;
        pSlow = pSlow->next;
    }
    return true;
}