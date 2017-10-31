//Given a binary search tree and a node in it, find the in - order successor of that node in the BST.

#include "Header.h";
TreeNode* Solution::inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode * c = root;
    TreeNode * successor = nullptr;
    while (c != nullptr && c->val != p->val) {
        if (c->val > p->val) {
            successor = c;
            c = c->left;
        }
        else {
            c = c->right;
        }
    }
    if (c == nullptr) {
        return nullptr;
    }
    if (c->right == nullptr) {
        return successor;
    }
    c = c->right;
    while (c->left) {
        c = c->left;
    }
    return c;
}