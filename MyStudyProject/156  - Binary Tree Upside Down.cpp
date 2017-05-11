//Given a binary tree where all the right nodes are either leaf nodes with a sibling(a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes.Return the new root.
//For example :
//Given a binary tree { 1,2,3,4,5 },
//1
/// \
//2   3
/// \
//4   5
//
//return the root of the binary tree [4, 5, 2, #, #, 3, 1].
//4
/// \
//5   2
/// \
//3   1

#include "Header.h";

void postOrderTraverse(TreeNode *root, vector<int>& stack) {
    if (root == NULL) {
        return;
    }
    if (root->left) {
        postOrderTraverse(root->left, stack);
        if (root->right) {
            stack.push_back(root->right->val);
        }
    }
    stack.push_back(root->val);
}



TreeNode* Solution::upsideDownBinaryTree(TreeNode *root) {
    TreeNode* newRoot = NULL;

    if (!root) {
        return NULL;
    }
    vector<int> stack;
    postOrderTraverse(root, stack);

    //pre order construct
    newRoot = new TreeNode(stack.front());
    TreeNode* tmp = newRoot;
    stack.erase(stack.begin());
    while (!stack.empty()) {       
        tmp->left = new TreeNode(stack.front());
        stack.erase(stack.begin());
        if (!stack.empty()) {
            tmp->right = new TreeNode(stack.front());
            stack.erase(stack.begin());
            tmp = tmp->right;
        }
    }
    return newRoot;
}