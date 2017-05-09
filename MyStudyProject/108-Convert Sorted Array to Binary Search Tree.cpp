//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
#include "Header.h";

TreeNode* buildBST(vector<int>A, int start, int end) {
    if (start == end) {
        return new TreeNode(A[start]);
    }
    if (start > end) {
        return nullptr;
    }
    int rootIndex= (start+end) / 2 + (start+end) % 2;
    TreeNode* root = new TreeNode(A[rootIndex]);
    root->left = buildBST(A, start, rootIndex - 1);
    root->right = buildBST(A, rootIndex + 1, end);
    return root;
}
TreeNode* Solution::sortedArrayToBST(vector<int> A) {
    TreeNode* root = nullptr;
    if (A.size() > 0) {
        root = buildBST(A, 0, A.size() - 1);
    }
    return root;
}