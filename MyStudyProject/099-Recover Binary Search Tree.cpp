//Two elements of a binary search tree(BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward.Could you devise a constant space solution ?

#include "Header.h";
TreeNode* n1;
TreeNode* n2; TreeNode *pre;
void inOrderBST(TreeNode* root) {
    if (!root) {
        return;
    }
    inOrderBST(root->left);
    if(pre && pre->val>root->val) {
        if (!n1) {
            n1 = pre;
        }
        n2 = root;
    }
    pre = root;
    inOrderBST(root->right);
}
void Solution::recoverTree(TreeNode* root) {
    n1 = nullptr;
    n2 = nullptr;
    pre = nullptr;
    inOrderBST(root);
    if (n1&&n2) {
        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
}