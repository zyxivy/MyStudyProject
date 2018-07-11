//Given an integer array with no duplicates.A maximum tree building on this array is defined as follow :
//
//The root is the maximum number in the array.
//The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
//The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
//Construct the maximum tree by the given array and output the root node of this tree.
//
//Example 1:
//Input: [3, 2, 1, 6, 0, 5]
//	Output : return the tree root node representing the following tree :
//
//	   6
//		   / \
//		   3     5
//		   \ /
//		   2  0
//		   \
//		   1
//		   Note:
//	   The size of the given array will be in the range[1, 1000].
#include "Header.h";
TreeNode* Solution::constructMaximumBinaryTree(vector<int>& nums) {
	vector<TreeNode*> st;
	for (int i = 0; i < nums.size(); i++) {
		TreeNode* node = new TreeNode(nums[i]);
		while (!st.empty() && st.back()->val < nums[i]) {
			node->left = st.back();
			st.pop_back();
		}
		if (!st.empty()) {
			st.back()->right = node;
		}
		st.push_back(node);
	}
	return st.front();
}