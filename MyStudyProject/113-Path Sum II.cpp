//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//For example :
//Given the below binary tree and sum = 22,
//5
/// \
//4   8
/// / \
//11  13  4
/// \ / \
//7    2  5   1
//return
//[
//    [5, 4, 11, 2],
//    [5, 8, 4, 5]
//]

#include "Header.h";
void pathSums(TreeNode*root, int sum, vector<vector<int>>& ret, vector<int>& item) {
    bool result = false;
    if (!root->left && !root->right) {
        if (sum == root->val) {
            item.push_back(root->val);
            ret.push_back(item);
            item.pop_back();
        }
        return;
    }
    if (root->left && !root->right) {
        item.push_back(root->val);
        pathSums(root->left, sum - root->val, ret, item);
        item.pop_back();
        return;
    }
    if (!root->left && root->right) {
        item.push_back(root->val);
        pathSums(root->right, sum - root->val, ret, item);
        item.pop_back();
        return;
    }
    item.push_back(root->val);
    pathSums(root->left, sum - root->val, ret, item);
    pathSums(root->right, sum - root->val, ret, item);
    item.pop_back();
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ret;
    vector<int> item;
    if (root) {
        pathSums(root, sum, ret, item);
    }
    return ret;
}