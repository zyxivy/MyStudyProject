//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//1
/// \
//2   5
/// \   \
//3   4   6
//The flattened tree should look like :
//1
//\
//2
//\
//3
//\
//4
//\
//5
//\
//6
//click to show hints.
//
//Hints:
//If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

#include "Header.h";
TreeNode* getRightest(TreeNode* root) {
    while (root&&root->right) {
        root = root->right;
    }
    return root;
}
void preorderflatten(TreeNode* root) {
    if (!root) {
        return;
    }
    preorderflatten(root->left);
    if (root->left) {
        TreeNode* rightest = getRightest(root->left);
        if (rightest) {
            rightest->right = root->right;
        }
        root->right = root->left;
        root->left = nullptr;
    }
    preorderflatten(root->right);
}

TreeNode* prevNode = nullptr;
void Solution::flatten(TreeNode* root) {
    preorderflatten(root);


	//method2
	if (root == nullptr) {
		return;
	}
	flatten(root->right);
	flatten(root->left);
	root->right = prevNode;
	root->left = nullptr;
	prevNode = root;

}