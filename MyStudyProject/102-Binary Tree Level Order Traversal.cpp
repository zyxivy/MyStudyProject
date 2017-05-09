//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its level order traversal as :
//[
//    [3],
//    [9, 20],
//    [15, 7]
//]
//Subscribe to see w

#include "Header.h";
vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    vector<TreeNode*> level;
    if (!root) {
        return ret;
    }
    level.push_back(root);
    while (level.size() > 0) {
        vector<TreeNode*> tmplevel;
        vector<int> line;
        for (int i = 0;i < level.size() ;i++) {
            line.push_back(level[i]->val);
            if (level[i]->left){
                tmplevel.push_back(level[i]->left);
            }
            if (level[i]->right) {
                tmplevel.push_back(level[i]->right);
            }
        }
        level.clear();
        ret.push_back(line);
        if (tmplevel.size() > 0) {
            level = tmplevel;
        }
    }
    return ret;
}