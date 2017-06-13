//Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//For example :
//Given the following binary tree,
//1            <-- -
//    / \
//    2     3         <-- -
//    \     \
//    5     4       <-- -
//
//    You should return[1, 3, 4].

//This problem can be solve by using a queue. On each level of the tree, we add the right-most element to the results. 
#include "Header.h";
vector<int> Solution::rightSideView(TreeNode* root) {
    vector<int> result;
    vector<TreeNode*> queue;
    if (root == nullptr) {
        return result;
    }
    int curLevel = 0;
    int maxLeve = 0;

    queue.push_back(root);
    while (!queue.empty()) {
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            TreeNode* top = queue.front();
            queue.erase(queue.begin());
            if (i == 0) {
                result.push_back(top->val);
            }
            if (top->right) {
                queue.push_back(top->right);
            }
            if (top->left) {
                queue.push_back(top->left);
            }
        }
    }

    return result;
}