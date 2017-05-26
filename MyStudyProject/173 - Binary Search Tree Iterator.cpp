//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//Calling next() will return the next smallest number in the BST.
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree

#include "Header.h";

BSTIterator::BSTIterator(TreeNode *root) {
    m_root = root;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return m_root != NULL;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int result = 0;
    if (m_root) {
        result = m_root->val;

    }
    return result;
}