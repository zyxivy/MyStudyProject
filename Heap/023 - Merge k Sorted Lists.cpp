//Merge k sorted linked listsand return it as one sorted list.Analyze and describe its complexity.
//
//Example:
//
//Input:
//[
//	1->4->5,
//	1->3->4,
//	2->6
//]
//Output : 1->1->2->3->4->4->5->6

#include "pch.h";
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode* dummyHead = new ListNode(-1);
    ListNode* cur = dummyHead;
    priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;
    for (ListNode* l : lists) {
        if (l) {
            min_heap.push(l);
        }
    }

    while (!min_heap.empty()) {
        cur->next = min_heap.top();
        min_heap.pop();
        cur = cur->next;
        if (cur->next)
        {
            min_heap.push(cur->next);
        }
    }
    return dummyHead->next;
}