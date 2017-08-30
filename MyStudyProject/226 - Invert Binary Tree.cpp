//Invert a binary tree.
//4
/// \
//2     7
/// \ / \
//1   3 6   9
//to
//4
/// \
//7     2
/// \ / \
//9   6 3   1

#include "Header.h";

void InvertTreeRecur(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    TreeNode* left = node->left;
    TreeNode* right = node->right;
    if (left) {
        InvertTreeRecur(node->left);
    }
    if (right) {
        InvertTreeRecur(node->right);
    }
    TreeNode* tmp = left;
    node->left = node->right;
    node->right = tmp;
}
TreeNode* Solution::invertTree(TreeNode* root) {
    InvertTreeRecur(root);
    return root;
}