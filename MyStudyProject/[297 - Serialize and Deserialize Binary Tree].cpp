//Serialization is the process of converting a data structure or object into a sequence of bits 
//so that it can be stored in a file or memory buffer, 
//or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//Design an algorithm to serialize and deserialize a binary tree.
//There is no restriction on how your serialization / deserialization algorithm should work.
//You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//For example, you may serialize the following tree
//1
/// \
//2   3
/// \
//4   5
//as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree.
//You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//
//Note: Do not use class member / global / static variables to store states.Your serialize and deserialize algorithms should be stateless.

#include "Header.h";
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preOrderSerialize(root, s);
        return s;
    }

    void preOrderSerialize(TreeNode* node, string& s) {
        if (node == nullptr) {
            s.append("#,");
            return;
        }
        s.append(to_string(node->val) + ",");
        preOrderSerialize(node->left, s);
        preOrderSerialize(node->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;

        int len = data.length();
        int i = 0;
        int j = 0;
        while (i < len) {
            j = i;
            while (data[j] != ','&&j < len) {
                j++;
            }
            string s = data.substr(i, j - i);
            q.push(s);
            i = j + 1;
        }

        TreeNode* node = buildTree(q);
        return node;
    }

    TreeNode* buildTree(queue<string>& q) {
        string s = q.front();
        q.pop();
        if (s == "#") {
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(s));
        node->left = buildTree(q);
        node->right = buildTree(q);
        return node;
    }
};
