//Given a binary tree, return all root - to - leaf paths.
//For example, given the following binary tree :
//
//1
/// \
//2     3
//\
//5
//
//All root - to - leaf paths are :
//["1->2->5", "1->3"]

#include "Header.h";

void binaryTreePathsHelper(vector<string>& paths, string& path, TreeNode* node) {
    path += to_string(node->val);
    if (node->left == nullptr && node->right == nullptr) {        
        paths.push_back(path);
        return;
    }
    if (node->left) {
        path += "->";
        binaryTreePathsHelper(paths, path, node->left);
        path = path.substr(0, path.rfind("->"));
        
    }
    
    if (node->right) {
        path += "->";
        binaryTreePathsHelper(paths, path, node->right);
        path = path.substr(0, path.rfind("->"));
    }
}

vector<string> Solution::binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    string path;
    if (root == nullptr) {
        return paths;
    }
    binaryTreePathsHelper(paths, path, root);
    return paths;
}