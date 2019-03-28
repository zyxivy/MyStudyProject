//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//Example 1 :
//    2
//    / \
//    1   3
//    Binary tree[2, 1, 3], return true.
//    Example 2:
//1
/// \
//2   3
//Binary tree[1, 2, 3], return false.


#include "Header.h";

bool isValidBSTHelper(TreeNode* root, long min, long max) {
    if (!root) {
        return true;
    }
    if (root->val < max && root->val > min) {
        return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
    }
    else
    {
        return false;
    }

}

bool Solution::isValidBST(TreeNode* root) {
	//recursive
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);

	//iterative
	if (root == nullptr) {
		return true;
	}
	stack<TreeNode*> stk;
	TreeNode* prev = nullptr;
	while (root != nullptr || !stk.empty()) {
		while (root != nullptr) {
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		if (prev != nullptr && prev->val >= root->val) {
			return false;
		}
		prev = root;
		root = root->right;
	}
	return true;
}