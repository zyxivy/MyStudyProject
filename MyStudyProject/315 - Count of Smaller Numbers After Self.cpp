//You are given an integer array nums and you have to return a new counts array.The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//Example:
//Given nums = [5, 2, 6, 1]
//
//To the right of 5 there are 2 smaller elements(2 and 1).
//To the right of 2 there is only 1 smaller element(1).
//To the right of 6 there is 1 smaller element(1).
//To the right of 1 there is 0 smaller element.
//Return the array[2, 1, 1, 0].

#include "Header.h";
//vector<int> Solution::countSmaller(vector<int>& nums) {
    //vector<int> result;
    //if (nums.empty()) {
    //    return result;
    //}

    // result.push_back(0);
    //if (nums.size() == 1) {
    //    return result;
    //}

    //int len = nums.size();
    //for (int cur = len - 2; cur >= 0; cur--) {
    //    int i = cur + 1;
    //    int j = len - 1;
    //    while (i <= j && cur < i && cur < j && i<len && j<len) {
    //        int mid = i - (i - j) / 2;
    //        if (nums[cur] > nums[mid]) {
    //            j = mid - 1;
    //        }
    //        else{
    //            i = mid + 1;
    //        }
    //    }
    //    if (cur != j) {
    //        nums.insert(nums.begin() + j + 1, nums[cur]);
    //        nums.erase(nums.begin() + cur);
    //    }
    //    result.insert(result.begin(), len - j -1);
    //}
    //return result;
//}

//https://discuss.leetcode.com/topic/31405/9ms-short-java-bst-solution-get-answer-when-building-bst/2
class Node {

public:
    int m_val;
    int m_dup;
    int m_sum;

    Node* left;
    Node* right;
    Node(int val, int sum) {
        m_val = val;
        m_sum = sum;
        m_dup = 1;
        left = nullptr;
        right = nullptr;
    }
};

Node* countSmallerInsert(vector<int>& nums, vector<int>& result, Node* node, int i, int preSum) {
    if (node == nullptr) {
        node = new Node(nums[i], 0);
        result[i] = preSum;
    }
    else if (node->m_val == nums[i]) {
        node->m_dup++;
        result[i] = preSum + node->m_sum;
    }
    else if (node->m_val < nums[i]) {
        node->right = countSmallerInsert(nums, result, node->right, i, preSum + node->m_dup + node->m_sum);
    }
    else {
        node->m_sum++;
        node->left = countSmallerInsert(nums, result, node->left, i, preSum);
    }
    return node;
}
vector<int> Solution::countSmaller(vector<int>& nums) {
    int len = nums.size();
    if (nums.empty()) {
        vector<int> result;
        return result;
    }
    
    vector<int> result(len, 0);
    if (nums.size() == 1) {
        return result;
    }
    Node* root = nullptr;
    for (int i = len - 1; i >= 0; i--) {
        root=countSmallerInsert(nums, result, root, i, 0);
    }
    return result;
}