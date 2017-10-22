//Given a non - empty binary search tree and a target value, find the value in the BST that is closest to the target.
//Note:
//Given target value is a floating point.
//You are guaranteed to have only one unique value in the BST that is closest to the target.

#include "Header.h";
int Solution::closestValue(TreeNode* root, double target) {
    int result;
    if (root == nullptr) {
        return 0;
    }
    result = root->val;
    TreeNode* node = root;
    while (node) {
        result = fabs(target - result) < fabs(target - node->val) ? result : node->val;
        if (target > node->val) {
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return result;

    //iteration

    int tmp;
    if (target > root->val && root->right) {
        tmp = closestValue(root->right, target);
    }
    else if (target < root->val && root->left) {
        tmp = closestValue(root->left, target);
    }
    else {
        return root->val;
    }

    return abs(tmp - target) < abs(root->val - target) ? tmp : root->val;
}