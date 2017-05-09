//Given a singly linked list L : L0→L1→…→Ln - 1→Ln,
//reorder it to : L0→Ln→L1→Ln - 1→L2→Ln - 2→…
//You must do this in - place without altering the nodes' values.
//For example,
//Given{ 1,2,3,4 }, reorder it to{ 1,4,2,3 }.

/**
Analysis:

Let's see some examples:

{1, 2, 3, 4, 5, 6} ---> {1, 6, 2, 5, 3, 4}
{1, 2, 3, 4, 5, 6, 7} ---> {1, 7, 2, 6, 3, 5, 4}

One straightforward middle step of such reordering is :
{1, 2, 3, 4, 5, 6}  --> {1, 2, 3, 6, 5, 4} --> {1, 6, 2, 5, 3, 4}
{1, 2, 3, 4, 5, 6, 7}---> {1, 2, 3, 4, 7, 6, 5} ---> {1, 7, 2, 6, 3, 5, 4}

By reversing the last part of the linked list, we do not need to worried about the "parent" pointer anymore.The final step is just insert the each element in the last part into the first part(every two element).

So the algorithm implemented below can be summarized as :
Step 1  Find the middle pointer of the linked list(you can use the slow / fast pointers)
Step 2  Reverse the second part of the linked list(from middle->next to the end)
Step 3  Do the reordering. (inset every element in the second part in between the elements in the first part)
**/

#include "Header.h";
void Solution::reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    ListNode* first = head;
    ListNode* second = NULL;
    ListNode* pre = NULL;
    ListNode* cur = NULL;
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }

    //step 1 Find the middle pointer of the linked list
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
        }
        if (fast) {
            fast = fast->next;
        }
    }

    //Reverse the second part of the linked list, slow->next is the fist node of the second half.
    second = slow->next;
    slow->next = NULL;
    pre = second;
    cur = second->next;
    while (cur) {
        ListNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    second->next = NULL;
    second = pre;

    //Inset every element in the second part in between the elements in the first part
    while (second&&first) {
        ListNode* fnxt = first->next;
        ListNode* snxt = second->next;
        first->next = second;
        second->next = fnxt;
        first = fnxt;
        second = snxt;
    }
    ListNode* t = head;
}