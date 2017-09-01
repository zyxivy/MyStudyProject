//Given a binary tree, find the lowest common ancestor(LCA) of two given nodes in the tree.
//According to the definition of LCA on Wikipedia : “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants(where we allow a node to be a descendant of itself).”
//_______3______
/// \
//___5__          ___1__
/// \ / \
//6      _2       0       8
/// \
//7   4
//For example, the lowest common ancestor(LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

#include "Header.h";

TreeNode* pNode = nullptr;
bool lowestCommonAncestorPostOrderTraverse(TreeNode* node, TreeNode* p, TreeNode* q, bool& pMet, bool& qMet) {
    if (node == nullptr) {
        return false;
    }
    if (node->val == p->val) {
        pMet = true;
    }
    if (node->val == q->val) {
        qMet = true;
    }
    bool left = lowestCommonAncestorPostOrderTraverse(node->left, p, q, pMet, qMet);
    bool right = lowestCommonAncestorPostOrderTraverse(node->right, p, q, pMet, qMet);
    if (left && right) {
        pNode = node;
        return true;
    }
    return false;
}
TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* node;
    bool pMet = false;
    bool qMet = false;
    lowestCommonAncestorPostOrderTraverse(root, p, q, pMet, qMet);
    return pNode;
}