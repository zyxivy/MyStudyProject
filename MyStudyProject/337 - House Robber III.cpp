//The thief has found himself a new place for his thievery again.There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house.After a tour, the smart thief realized that "all houses in this place forms a binary tree".It will automatically contact the police if two directly - linked houses were broken into on the same night.
//Determine the maximum amount of money the thief can rob tonight without alerting the police.
//Example 1:
//3
/// \
//2   3
//\   \
//3   1
//Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//
//Example 2:
//3
/// \
//4   5
/// \   \
//1   3   1
//Maximum amount of money the thief can rob = 4 + 5 = 9.
#include "Header.h";

//https://leetcode.com/problems/house-robber-iii/discuss/79330

int robSub(TreeNode* root, map<TreeNode*, int>& mp) {
    if (!root) return 0;
    if (mp.find(root) != mp.end()) return mp[root];

    int val = 0;

    if (root->left != nullptr) {
        val += robSub(root->left->left, mp) + robSub(root->left->right, mp);
    }

    if (root->right != nullptr) {
        val += robSub(root->right->left, mp) + robSub(root->right->right, mp);
    }

    val = max(val + root->val, robSub(root->left, mp) + robSub(root->right, mp));
    mp[root] = val;

    return val;
}
int Solution::rob(TreeNode* root) {
    map<TreeNode*, int> mp;
    return robSub(root, mp);
}