//Given a non - empty binary search tree and a target value, find k values in the BST that are closest to the target.
//Note:
//Given target value is a floating point.
//You may assume k is always valid, that is : k ≤ total nodes.
//You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
//Follow up :
//Assume that the BST is balanced, could you solve it in less than O(n) runtime(where n = total nodes) ?
//Hint :
//    Consider implement these two helper functions :
//getPredecessor(N), which returns the next smaller node to N.
//getSuccessor(N), which returns the next larger node to N.
//Try to assume that each node has a parent pointer, it makes the problem much easier.
//Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
//You would need two stacks to track the path in finding predecessor and successor node separately.

#include "Header.h";

//http://www.cnblogs.com/jcliBlogger/p/4771342.html

void closestK(TreeNode* node, priority_queue<pair<double, int>>& q, double target, int k) {
    if (node == nullptr) {
        return;
    }
    q.push(make_pair(fabs(target - node->val), node->val));
    if (q.size() > k) {
        q.pop();
    }
    closestK(node->left, q, target, k);
    closestK(node->right, q, target, k);
}
vector<int> Solution::closestKValues(TreeNode* root, double target, int k) {
    priority_queue<pair<double, int>> q;
    vector<int> closest;

    closestK(root, q, target, k);

    while (!q.empty()) {
        closest.push_back(q.top().second);
        q.pop();
    }
    return closest;
}

//https://discuss.leetcode.com/topic/22940/ac-clean-java-solution-using-two-stacks/4

void closestKValues2Traverse(TreeNode* node, bool inOrder, vector<int>& s, double target) {
    if (node == nullptr) {
        return;
    }
    if (inOrder) {
        closestKValues2Traverse(node->left, true, s, target);
    }
    else {
        closestKValues2Traverse(node->right, false, s, target);
    }

    //crucial. make the top of inOrder and revOrder stack predecessor and successor of target
    if (inOrder && node->val > target) {
        return;
    }
    if (!inOrder && node->val < target) {
        return;
    }

    s.push_back(node->val);

    if (inOrder) {
        closestKValues2Traverse(node->right, true, s, target);
    }
    else {
        closestKValues2Traverse(node->left, false, s, target);
    }
}

vector<int> closestKValues2(TreeNode* root, double target, int k) {
    vector<int> inOrder;
    vector<int> revOrder;
    closestKValues2Traverse(root, true, inOrder, target);
    closestKValues2Traverse(root, false, revOrder, target);

    vector<int> closest;
    while (k-- > 0) {
        if (inOrder.empty()) {
            closest.push_back(revOrder.back());
            revOrder.pop_back();
        }
        else if (revOrder.empty()) {
            closest.push_back(inOrder.back());
            inOrder.pop_back();
        }
        else if (fabs(inOrder.back() - target) < fabs(revOrder.back() - target)) {
            closest.push_back(inOrder.back());
            inOrder.pop_back();
        }
        else{
            closest.push_back(revOrder.back());
            revOrder.pop_back();
        }
    }
    return closest;
}