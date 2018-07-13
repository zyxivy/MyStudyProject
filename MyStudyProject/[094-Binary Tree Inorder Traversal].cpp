//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree[1, null, 2, 3],
//1
//\
//2
///
//3
//return[1, 3, 2].
//
//Note: Recursive solution is trivial, could you do it iteratively ?

#include "Header.h";

void inorderRecursive(TreeNode* node, vector<int>& ret) {
    if (node == nullptr) {
        return;
    }
    inorderRecursive(node->left, ret);
    ret.push_back(node->val);
    inorderRecursive(node->right, ret);
}
vector<int> Solution::inorderTraversal(TreeNode* root) {
    //recursive
    vector<int> ret;
    {
        //inorderRecursive(root, ret);
    }

    vector<TreeNode*> stack;
    TreeNode* node = root;
    while (node || stack.size()!=0) {
        if (node) {
            stack.push_back(node);
            node = node->left;
        }
        else {
            node = stack.back();
            ret.push_back(node->val);
            stack.pop_back();
            node = node->right;
        }

    }
    return ret;
}