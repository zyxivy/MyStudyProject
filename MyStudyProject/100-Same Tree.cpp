//Given two binary trees, write a function to check if they are equal or not.
//
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
#include "Header.h";

bool preOrder(TreeNode*p, TreeNode*q) {
    if ((p&&!q) || (!p&&q)) {
        return false;
    }
    if (!p&&!q) {
        return true;
    }
    if (p->val != q->val) {
        return false;
    }
    return preOrder(p->left, q->left) && preOrder(p->right, q->right);
}
bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    return preOrder(p, q);
}