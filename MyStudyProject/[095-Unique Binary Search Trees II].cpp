//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//Given n = 3, your program should return all 5 unique BST's shown below.
//
//1         3     3      2      1
//\ / / / \      \
//3     2     1      1   3      2
/// / \                 \
//2     1         2                 3

#include "Header.h";

vector<TreeNode *> genBST(int min, int max) {
    vector<TreeNode *> ret;
    if (min>max) {
        ret.push_back(NULL);
        return ret;
    }

    for (int i = min; i <= max; i++) {
        vector<TreeNode*> leftSubTree = genBST(min, i - 1);
        vector<TreeNode*> rightSubTree = genBST(i + 1, max);
        for (int j = 0; j<leftSubTree.size(); j++) {
            for (int k = 0; k<rightSubTree.size(); k++) {
                TreeNode *root = new TreeNode(i);
                root->left = leftSubTree[j];
                root->right = rightSubTree[k];
                ret.push_back(root);
            }
        }
    }

    return ret;
}
vector<TreeNode*> Solution::generateTrees(int n) {
    vector<TreeNode*> ret;
    if (n == 0) {
        return ret;
    }
    ret = genBST(1, n);
    return ret;
}