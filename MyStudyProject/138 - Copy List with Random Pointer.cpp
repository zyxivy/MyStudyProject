//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//Return a deep copy of the list.

#include "Header.h";
RandomListNode* Solution::copyRandomList(RandomListNode *head) {
    if (head == NULL)
        return NULL;

    RandomListNode* newHead = new RandomListNode(0);
    map<RandomListNode*, RandomListNode*> map;


    RandomListNode* pCurr = head;
    RandomListNode* pNew = newHead;
    while (pCurr) {
        RandomListNode *tmp = new RandomListNode(pCurr->label);
        pNew->next = tmp;
        map[pCurr] = tmp;
        pCurr = pCurr->next;
        pNew = pNew->next;
    }
    pCurr = head;
    pNew = newHead->next;
    while (pCurr) {
        if (pCurr != NULL) {
            pNew->random = map[pCurr->random];
        }
        pCurr = pCurr->next;
        pNew = pNew->next;
    }

    return newHead->next;
}