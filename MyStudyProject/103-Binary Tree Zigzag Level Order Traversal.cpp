//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//return its zigzag level order traversal as :
//[
//    [3],
//    [20, 9],
//    [15, 7]
//]
#include "Header.h";
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    vector<TreeNode*> level;
    bool dir = false;
    if (!root) {
        return ret;
    }
    level.push_back(root);
    while (level.size() > 0) {
        vector<TreeNode*> tmplevel;
        vector<int> line;
        for (int i = 0;i < level.size();i++) {
            if (level[i]->left) {
                tmplevel.push_back(level[i]->left);
            }
            if (level[i]->right) {
                tmplevel.push_back(level[i]->right);
            }
        }
        if (dir) {
            for (int i = 0;i < level.size();i++) {
                line.push_back(level[i]->val);
            }
        }
        else
        {
            for (int i = level.size() -1;i >=0;i--) {
                line.push_back(level[i]->val);
            }
        }
        dir = !dir;
        level.clear();
        ret.push_back(line);
        if (tmplevel.size() > 0) {
            level = tmplevel;
        }
    }
    return ret;
}