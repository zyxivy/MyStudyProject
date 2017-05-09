//Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its bottom - up level order traversal as :
//[
//    [15, 7],
//    [9, 20],
//    [3]
//]

#include "Header.h";
vector<vector<int>> Solution::levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ret;
    vector<TreeNode*> level;
    if (!root) {
        return ret;
    }
    level.push_back(root);
    while (level.size() > 0) {
        vector<TreeNode*> tmplevel;
        vector<int> line;
        for (int i = 0;i < level.size();i++) {
            line.push_back(level[i]->val);
            if (level[i]->left) {
                tmplevel.push_back(level[i]->left);
            }
            if (level[i]->right) {
                tmplevel.push_back(level[i]->right);
            }
        }
        level.clear();
        ret.insert(ret.begin(),line);
        if (tmplevel.size() > 0) {
            level = tmplevel;
        }
    }
    return ret;
}