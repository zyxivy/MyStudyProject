//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//But the following[1, 2, 2, null, 3, null, 3] is not:
//1
/// \
//2   2
//\   \
//3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.

#include "Header.h";
bool isSymmetricTree(TreeNode* a, TreeNode* b) {
    if ((!a &&b) || (a&&!b)) {
        return false;
    }
    if (!a&&!b) {
        return true;
    }
    if (a->left->val != b->right-> val) {
        return false;
    }
    return isSymmetricTree(a->left, b->right) && isSymmetricTree(a->right, b->left);
}
bool Solution::isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    isSymmetricTree(root->left, root->right);

	//Iterative
	TreeNode *left, *right;
	if (!root)
		return true;

	queue<TreeNode*> q1, q2;
	q1.push(root->left);
	q2.push(root->right);
	while (!q1.empty() && !q2.empty()) {
		left = q1.front();
		q1.pop();
		right = q2.front();
		q2.pop();
		if (NULL == left && NULL == right)
			continue;
		if (NULL == left || NULL == right)
			return false;
		if (left->val != right->val)
			return false;
		q1.push(left->left);
		q1.push(left->right);
		q2.push(right->right);
		q2.push(right->left);
	}
	return true;
}