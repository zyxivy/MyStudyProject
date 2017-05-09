//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.{
#include "Header.h";

int findDepth(TreeNode* root) {
    int d = 0;
    if (!root) {
        return 0;
    }
    int d1 = findDepth(root->left);
    int d2 = findDepth(root->right);
    d = d1 > d2 ? d1 + 1 : d2 + 1;
    return d;
}
int Solution::maxDepth(TreeNode* root) {
    int depth = 0;
    if (!root) {
        return 0;
    }
    depth = findDepth(root);
    return depth;
}