//Given a binary tree, find all leaves and then remove those leaves.Then repeat the previous steps until the tree is empty.
//Example:
//Given binary tree
//1
/// \
//2   3
/// \
//4   5
//Returns[4, 5, 3], [2], [1].
//Explanation:
//1. Remove the leaves[4, 5, 3] from the tree
//1
///
//2
//2. Remove the leaf[2] from the tree
//1
//3. Remove the leaf[1] from the tree
//[]
//Returns[4, 5, 3], [2], [1].

#include "Header.h";
//use height as index in the result vector<vector<int>>
//height of a node is the number of edges from the node to the deepest leaf
int findLeavesHelper(TreeNode* root, vector<vector<int>>& ans) {
    if (root == nullptr) {
        return -1; //leaves have height of 0;
    }
    int height = 1 + max(findLeavesHelper(root->left, ans), findLeavesHelper(root->right, ans));
    if (height >- ans.size()) {
        ans.resize(height + 1);
    }
    ans[height].push_back(root->val);
    return height;
}

vector<vector<int>> Solution::findLeaves(TreeNode* root) {
    vector<vector<int>> ans;
    findLeavesHelper(root, ans);
    return ans;
}