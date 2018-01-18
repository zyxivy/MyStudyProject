//Given a binary tree, find the largest subtree which is a Binary Search Tree(BST), where largest means subtree with largest number of nodes in it.

#include "Header.h";

void isValidBSTlargestBSTSubtree(TreeNode* root, int& mn, int& mx, int& res) {
    if (!root) {
        return;
    }
    int left = 0, left_min = INT_MIN, left_max = INT_MAX;
    int right = 0, right_min = INT_MIN, right_max = INT_MAX;

    isValidBSTlargestBSTSubtree(root->left, left_min, left_max, left);
    isValidBSTlargestBSTSubtree(root->right, right_min, right_max, right);
    if ((root->left == nullptr || root->val > left) && (root->right == nullptr || root->val < right)) {
        res = left + right + 1;
        mn = root->left ? left_min : root->val;
        mx = root->right ? right_max : root->val;
    }
    else {
        res = max(left, right);
    }
}
int Solution::largestBSTSubtree(TreeNode* root) {
    int res = 0, mn = INT_MIN, mx = INT_MAX;
    isValidBSTlargestBSTSubtree(root, mn, mx, res);
    return res;
}