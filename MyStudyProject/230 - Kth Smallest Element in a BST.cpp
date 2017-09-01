//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//Note:
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//Follow up :
//What if the BST is modified(insert / delete operations) often and you need to find the kth smallest frequently ? How would you optimize the kthSmallest routine ?

#include "Header.h";


void inOrderKthSmallest(TreeNode* node, vector<int>& vc, int k) {
    if (node == nullptr || vc.size() == k) {
        return;
    }

    inOrderKthSmallest(node->left, vc, k);
    if (vc.size() >= k) {
        return;
    }
    vc.push_back(node->val);
    if (vc.size() == k) {
        return;
    }
    inOrderKthSmallest(node->right, vc, k);
    if (vc.size() >= k) {
        return;
    }
}
int Solution::kthSmallest(TreeNode* root, int k) {
    vector<int> vc;
    if (root == nullptr) {
        return 0;
    }
    inOrderKthSmallest(root, vc, k);
    return vc.back();
}