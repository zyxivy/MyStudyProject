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
    queue<TreeNode*> level;
    if (!root) {
        return ret;
    }
    level.push(root);
    while (level.size() > 0) {
        vector<int> line;
		int n = level.size();
        for (int i = 0;i < n ;i++) {
            line.push_back(level.front()->val);
            if (level.front()->left){
				level.push(level.front()->left);
            }
            if (level.front()->right) {
				level.push(level.front()->right);
            }
			level.pop();
        }
        ret.push_back(line);
    }
    return ret;
}