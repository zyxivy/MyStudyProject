//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

#include "Header.h";
void searchMinPath(TreeNode *root, int curDpt, int &minDpt) {
    if (!root) {
        minDpt = 0;
        return;
    }

    curDpt++;
    if (!root->left && !root->right) {   // reach a leaf node
        minDpt = minDpt < curDpt ? minDpt : curDpt;
        return;
    }

    if (root->left) searchMinPath(root->left, curDpt, minDpt);
    if (root->right) searchMinPath(root->right, curDpt, minDpt);

}
int Solution::minDepth(TreeNode* root) {
    int minDpt = INT_MAX;
    searchMinPath(root, 0, minDpt);
    return minDpt;
}