//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//Calling next() will return the next smallest number in the BST.
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree

#include "Header.h";

class BSTIterator {
public:
    BSTIterator(TreeNode *root);
    /** @return whether we have a next smallest number */
    bool hasNext();
    /** @return the next smallest number */
    int next();
private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
};

BSTIterator::BSTIterator(TreeNode *root) {
    pushAll(root);
}


/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    if (st.empty()) {
        return 0;
    }
    TreeNode* node = st.top();
    st.pop();
    pushAll(node->right);
    return node->val;
}