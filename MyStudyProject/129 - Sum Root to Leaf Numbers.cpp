//Given a binary tree containing digits from 0 - 9 only, each root - to - leaf path could represent a number.
//An example is the root - to - leaf path 1->2->3 which represents the number 123.
//Find the total sum of all root - to - leaf numbers.
//For example,
//1
/// \
//2   3
//
//The root - to - leaf path 1->2 represents the number 12.
//The root - to - leaf path 1->3 represents the number 13.
//Return the sum = 12 + 13 = 25.

#include "Header.h";

void inOrderTraverse(TreeNode* node, int num, int &sum) {
    if (node == NULL) {
        return;
    }
    num = num * 10 + node->val;
    if (node->left == NULL && node->right == NULL) {
        sum += num;
        return;
    }
    if (node->left) {
        inOrderTraverse(node->left, num, sum);
    }

    if (node->right) {
        inOrderTraverse(node->right, num, sum);
    }
}

int Solution::sumNumbers(TreeNode* root) {
    int result = 0;

    inOrderTraverse(root, 0, result);
    return result;
}

