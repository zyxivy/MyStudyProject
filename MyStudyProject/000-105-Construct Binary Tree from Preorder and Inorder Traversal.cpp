//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
#include "Header.h";
int search(vector<int> A, int target, int start, int end) {
    if (target == A[end]) {
        return end;
    }
    for (int i = start;i <= end;i++) {
        if (target == A[i]) {
            return i;
        }
    }
    return -1;
}

void build(TreeNode* root, vector<int> preorder, vector<int> inorder, int preorderRoot, int inorderlow, int inorderhigh) {
    int inorderRoot = search(inorder, root->val, inorderlow, inorderhigh);
    if (inorderRoot == -1) {
        return;
    }
    if (inorderRoot > inorderlow) {
        TreeNode* left = new TreeNode(preorder[preorderRoot + 1]);
        root->left = left;
        build(left, preorder, inorder, preorderRoot + 1, inorderlow, inorderRoot - 1);
    }
    if (inorderRoot < inorderhigh) {
        TreeNode* right = new TreeNode(preorder[inorderRoot + 1]);
        root->right = right;
        build(right, preorder, inorder, inorderRoot + 1, inorderRoot + 1, inorderhigh);
    }
}
TreeNode* Solution::buildTree(vector<int> preorder, vector<int> inorder) {
    TreeNode* root;
    if (preorder.size() > 0) {
        root = new TreeNode(preorder[0]);
        build(root, preorder, inorder, 0, 0, inorder.size() - 1);
    }
    return root;
}