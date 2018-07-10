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

int getMax(TreeNode* root, int &maxmax) {
    if (root == nullptr) {
        return 0;
    }
    int left = max(0,getMax(root->left, maxmax));
    int right = max(0,getMax(root->right, maxmax));
    int cur = root->val;
	maxmax = max(maxmax, cur+left+right);

    return max(left, right)+cur;//Once a path go down, it can't go up, hence max path through cur is either through left sub-tree or right sub-tree.
}

int Solution::maxPathSum(TreeNode* root) {
    int max = INT_MIN;
    getMax(root, max);
    return max;
}