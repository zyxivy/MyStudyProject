//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9, 3, 15, 20, 7]
//postorder = [9, 15, 7, 20, 3]
//Return the following binary tree :
//
//3
/// \
//9  20
/// \
//15   7

#include "Header.h";

TreeNode* buildTreePostInHelper(vector<int> inorder, vector<int> postorder, unordered_map<int, int> mp,
	int pos, int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd) {
		return nullptr;
	}
	TreeNode* root = new TreeNode(postorder[postEnd]);
	pos = mp[postorder[postEnd]];
	//why postStart+pos-inStart - 1
	//why postEnd-inEnd+pos	
	root->left = buildTreePostInHelper(inorder, postorder, mp, pos, inStart, pos - 1, postStart, postStart+pos-inStart - 1);
	root->right = buildTreePostInHelper(inorder, postorder, mp, pos, pos+1, inEnd, postEnd-inEnd+pos, postEnd-1);
	return root;
}
TreeNode* Solution::buildTreePostIn(vector<int>& inorder, vector<int>& postorder) {
	if (inorder.empty() || postorder.empty()||inorder.size()!=postorder.size()) {
		return nullptr;
	}
	unordered_map<int, int> mp;
	for (int i = 0; i < inorder.size(); i++) {
		mp[inorder[i]] = i;
	}
	TreeNode* root = buildTreePostInHelper(inorder, postorder, mp, 0, 0, inorder.size()-1, 0, postorder.size()-1);
	return root;
}