//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia :
//In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.It can have between 1 and 2h nodes inclusive at the last level h.

#include "Header.h";

 int getLeftHeight(TreeNode* n) {
	if (n == nullptr) return 0;

	int height = 0;
	while (n->left != nullptr) {
		height++;
		n = n->left;
	}
	return height;
}

 int getRightHeight(TreeNode* n) {
	if (n == nullptr) return 0;

	int height = 0;
	while (n->right != nullptr) {
		height++;
		n = n->right;
	}
	return height;
}
int Solution::countNodes(TreeNode* root) {
	if (root == nullptr)
		return 0;

	int left = getLeftHeight(root) + 1;
	int right = getRightHeight(root) + 1;

	if (left == right) {
		return (2 << (left - 1)) - 1;
	}
	else {
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
}