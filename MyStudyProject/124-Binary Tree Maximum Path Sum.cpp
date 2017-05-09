//Given a binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent - child connections.The path does not need to go through the root.
//
//For example :
//Given the below binary tree,
//
//1
/// \
//2   3
//Return 6.
#include "Header.h";

int getMax(TreeNode* root, int &max) {
    if (root == nullptr) {
        return 0;
    }
    int left = getMax(root->left, max);
    int right = getMax(root->right, max);
    int cur = root->val;
    int curMax = (cur + left) > (cur + right) ? (cur + left) : (cur + right);
    curMax = curMax > cur ? curMax : cur;

    max = max > (curMax > (cur + left + right) ? curMax : (cur + left + right)) ? max : (curMax > (cur + left + right) ? curMax : (cur + left + right));
    return curMax;
}

int Solution::maxPathSum(TreeNode* root) {
    int max = INT_MIN;
    getMax(root, max);
    return max;
}