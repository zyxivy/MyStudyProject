//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
#include "Header.h";

//http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html
//类似merge sort，每次将所有的list两两之间合并，直到所有list合并成一个。如果用迭代而非递归，则空间复杂度为O(1)。时间复杂度：
//2n * k / 2 + 4n * k / 4 + ... + (2 ^ x)n * k / (2 ^ x) = nk * x
//k / (2 ^ x) = 1 -> 2 ^ x = k->x = log2(k)
//所以时间复杂度为O(nk log(k))

ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    if (l1->val <= l2->val) {
        l1->next = merge2Lists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = merge2Lists(l1, l2->next);
        return l2;
    }
}
ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
    int len = lists.size();
    int begin = 0;
    int end = len - 1;
    while (end>0) {
        int begin = 0;
        while (begin<end) {
            lists[begin] = merge2Lists(lists[begin], lists[end]); 
            begin++;
            end--;
        }
    }
    return lists[0];

    return nullptr;
}