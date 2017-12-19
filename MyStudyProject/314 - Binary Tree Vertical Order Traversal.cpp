//Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
//If two nodes are in the same row and column, the order should be from left to right.
//Examples:
//Given binary tree[3, 9, 20, null, null, 15, 7],
//3
/// \
//9  20
/// \
//15   7
//
//return its vertical order traversal as :
//[
//    [9],
//    [3, 15],
//    [20],
//    [7]
//]
//
//Given binary tree[3, 9, 20, 4, 5, 2, 7],
//_3_
/// \
//9    20
/// \ / \
//4   5 2   7
//
//return its vertical order traversal as :
//[
//    [4],
//    [9],
//    [3, 5, 2],
//    [20],
//    [7]
//]

#include "Header.h";
    //BFS, put node, col into queue at the same time
    //Every left child access col - 1 while right child col + 1
    //This maps node into different col buckets
    //Get col boundary min and max on the fly
    //Retrieve result from cols

//https://discuss.leetcode.com/topic/31954/5ms-java-clean-solution
vector<vector<int>> Solution::verticalOrder(TreeNode* root) {
    vector<vector<int>> result;

    if (root == nullptr) {
        return result;
    }

    //col : list of node vals
    map<int, vector<int>> mp;
    queue<TreeNode*> q;

    queue<int> col;
    col.push(0);
    int minCol = 0;//starting from 0 as we assign root with col=0;
    int maxCol = 0;

    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.back();
        q.pop();

        int curCol = col.back();
        col.pop();

        mp[curCol].push_back(node->val);
     
        if (node->left != nullptr) {
            q.push(node->left);
            col.push(curCol - 1);
            minCol = min(minCol, curCol - 1);
        }

        if (node->right != nullptr) {
            q.push(node->right);
            col.push(curCol + 1);
            minCol = min(minCol, curCol + 1);
        }
    }

    for (int i = minCol; i < maxCol; i++) {
        result.push_back(mp[i]);
    }

    return result;
}