//Given a binary tree, count the number of uni - value subtrees.
//A Uni - value subtree means all nodes of the subtree have the same value.
//
//Given binary tree,
//5
/// \
//1   5
/// \   \
//5   5   5
//
//return 4.

#include "Header.h";
int thisCount = 0;
int countUnivalSubtreesHelper(TreeNode* root) {
    if (root == nullptr) {
        return INT_MAX;
    }

    // Divide
    int left = countUnivalSubtreesHelper(root->left);
    int right = countUnivalSubtreesHelper(root->right);

    // left and right are all empty
    if (left == INT_MAX && right == INT_MAX) {
        thisCount++;
        return root->val;
    }
    else if (left == INT_MAX || right == INT_MAX) {
        if (root->val == left || root->val == right) {
            thisCount++;
            return root->val;
        }
        else {
            return INT_MIN;
        }
    }
    else {
        if (root->val == left && root->val == right) {
            thisCount++;
            return root->val;
        }
        else {
            return INT_MIN;
        }
    }
}
int Solution::countUnivalSubtrees(TreeNode* root){
    if (root == nullptr) {
        return 0;
    }

    countUnivalSubtreesHelper(root);

    return thisCount;
}