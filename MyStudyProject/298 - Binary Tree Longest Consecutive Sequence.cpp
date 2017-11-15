//Given a binary tree, find the length of the longest consecutive sequence path.
//The path refers to any sequence of nodes from some starting node to any node in the tree along the parent - child connections.The longest consecutive path need to be from parent to child(cannot be the reverse).
//For example,
//1
//\
//3
/// \
//2   4
//\
//5
//Longest consecutive sequence path is 3 - 4 - 5, so return 3.
//2
//\
//3
///
//2
///
//1
//Longest consecutive sequence path is 2 - 3, not 3 - 2 - 1, so return 2.

#include "Header.h";

int longestConsecutiveDFS(TreeNode *root, TreeNode *parent, int len) {
    if (!root) return len;
    len = (parent && root->val == parent->val + 1) ? len + 1 : 1;
    return max(len, max(longestConsecutiveDFS(root->left, root, len), longestConsecutiveDFS(root->right, root, len)));
}
int Solution::longestConsecutive(TreeNode* root) {
    return longestConsecutiveDFS(root, nullptr, 0);
}
