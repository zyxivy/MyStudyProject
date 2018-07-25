//Given a binary tree, find the leftmost value in the last row of the tree.
//
//Example 1:
//Input:
//
//2
/// \
//1   3
//
//Output:
//1
//Example 2 :
//	Input :
//
//	1
//	/ \
//	2   3
//	/   / \
//	4   5   6
//	/
//	7
//
//	Output:
//7

#include "Header.h";
int Solution::findBottomLeftValue(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* cur;
	while (!q.empty()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			cur = q.front();
			q.pop();
			if (cur->right) {
				q.push(cur->right);
			}
			if (cur->left) {
				q.push(cur->left);
			}
		}		
	}
	return cur->val;
}