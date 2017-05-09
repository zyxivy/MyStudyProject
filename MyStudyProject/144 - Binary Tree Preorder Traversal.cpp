//Given a binary tree, return the preorder traversal of its nodes' values.
//For example :
//Given binary tree{ 1,#,2,3 },
//1
//\
//2
///
//3
//
//return[1, 2, 3].
//Note: Recursive solution is trivial, could you do it iteratively ?

#include "Header.h";
vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<TreeNode*> stack;
    vector<int> result;

    if (!root) {
        return result;
    }

    stack.push_back(root);
    while (!stack.empty()) {
        TreeNode* node = stack.back();
        stack.pop_back();
        result.push_back(node->val);
        if (node->right) {
            stack.push_back(node->right);
        }
        if (node->left) {
            stack.push_back(node->left);
        }
    }

    return result;
}