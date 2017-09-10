//Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
//You may assume each number in the sequence is unique.
//Follow up :
//Could you do it using only constant space complexity ?


//https://asanchina.wordpress.com/2016/01/12/255-verify-preorder-sequence-in-binary-search-tree/
#include "Header.h";
bool Solution::verifyPreorder(vector<int> preorder) {
    stack<int> inorder, tmp;
    int size = preorder.size();
    for (int i = 0; i < size; ++i)
    {
        if (!inorder.empty() && preorder[i] < inorder.top())
            return false;
        while (!tmp.empty() && tmp.top() < preorder[i])
        {
            inorder.push(tmp.top());
            tmp.pop();
        }
        tmp.push(preorder[i]);
    }
    return true;
}