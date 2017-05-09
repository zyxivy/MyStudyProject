//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree ? Would your previous solution still work ?
//
//Note :
//
//    You may only use constant extra space.
//    For example,
//    Given the following binary tree,
//    1
//    / \
//    2    3
//    / \    \
//    4   5    7
//    After calling your function, the tree should look like :
//1->NULL
/// \
//2 -> 3->NULL
/// \    \
//4-> 5 -> 7->NULL
#include "Header.h";
void connectsII(TreeLinkNode* root) {
    if (!root) {
        return;
    }
    if (root->left && root->right) {
        root->left->next = root->right;
        if (root->next) {
            TreeLinkNode* tmp = root->next;
            while (tmp->next && !tmp->left && !tmp->right) {
                tmp = tmp->next;
            }
            if (tmp->left) {
                root->right->next = tmp->left;
            }
            else
            {
                root->right->next = tmp->right;
            }
        }
    }
    else if (root->left && !root->right) {
        if (root->next) {
            TreeLinkNode* tmp = root->next;
            while (tmp->next && !tmp->left && !tmp->right) {
                tmp = tmp->next;
            }
            if (tmp->left) {
                root->left->next = tmp->left;
            }
            else
            {
                root->left->next = tmp->right;
            }
        }
    }
    else if (!root->left && root->right) {
        if (root->next) {
            TreeLinkNode* tmp = root->next;
            while (tmp->next && !tmp->left && !tmp->right) {
                tmp = tmp->next;
            }
            if (tmp->left) {
                root->right->next = tmp->left;
            }
            else
            {
                root->right->next = tmp->right;
            }
        }
    }
    connectsII(root->right);
    connectsII(root->left);
}
void Solution::connectII(TreeLinkNode *root) {
    if (!root) {
        return;
    }
    connectsII(root);
}