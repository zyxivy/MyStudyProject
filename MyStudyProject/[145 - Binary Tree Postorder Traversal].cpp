//Given a binary tree, return the postorder traversal of its nodes' values.
//For example :
//Given binary tree{ 1,#,2,3 },
//1
//\
//2
///
//3
//
//return[3, 2, 1].
//Note: Recursive solution is trivial, could you do it iteratively ?

#include "Header.h";

vector<int> Solution::postorderTraversal(TreeNode* root) {
    vector<int> result;
    vector<TreeNode*> stack;

    if (!root) {
        return result;
    }
    stack.push_back(root);
    while (!stack.empty()) {
        TreeNode* node = stack.back();
        if (node->left == NULL && node->right == NULL) {
            result.push_back(node->val);
            stack.pop_back();
        }
        else {
            if (node->right != NULL) {
                stack.push_back(node->right);
                node->right = NULL;
            }
            if (node->left != NULL) {
                stack.push_back(node->left);
                node->left = NULL;
            }
        }
    }
    return result;
}
