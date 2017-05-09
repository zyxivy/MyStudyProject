//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

#include "Header.h";
int getHeight(TreeNode* root) {
    if (root == nullptr) {
        return 1;
    }
    int leftH = getHeight(root->left) + 1;
    int rightH = getHeight(root->right) + 1;
    return leftH > rightH ? leftH : rightH;
}
bool isBalance(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    if (l == r || r == l - 1 || l == r - 1) {
        return isBalance(root->left) && isBalance(root->right);
    }
    else {
        return false;
    }
}
bool Solution::isBalanced(TreeNode* root) {
    bool ret = false;
    ret = isBalance(root);
    return ret;
}