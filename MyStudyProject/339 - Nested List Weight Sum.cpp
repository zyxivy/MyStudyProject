//Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
//Each element is either an integer, or a list – whose elements may also be integers or other lists.
//Example 1:
//Given the list[[1, 1], 2, [1, 1]], return 10. (four 1’s at depth 2, one 2 at depth 1)
//Example 2 :
//    Given the list[1, [4, [6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 42 + 63 = 27)
//
#include "Header.h";

// // This is the interface that allows for creating nested lists.
// // You should not implement it, or speculate about its implementation
//class NestedInteger {
//public:
//      // @return true if this NestedInteger holds a single integer, rather than a nested list.
//      bool isInteger();
// 
//      // @return the single integer that this NestedInteger holds, if it holds a single integer
//      // Return null if this NestedInteger holds a nested list
//      bool getInteger();
// 
//      // @return the nested list that this NestedInteger holds, if it holds a nested list
//      // Return null if this NestedInteger holds a single integer
//      vector<NestedInteger> getList();
//  }

int DFSdepthSum(vector<NestedInteger>& nestedList, int depth) {
    int n = (int)nestedList.size();
    int sum = 0;
    for (int i = 0; i<n; i++) {
        if (nestedList[i].isInteger()) {
            sum += nestedList[i].getInteger()*depth;
        }
        else {
            vector<NestedInteger> l = nestedList[i].getList();
            sum += DFSdepthSum(l, depth + 1);
        }
    }
    return sum;
}

int Solution::depthSum(vector<NestedInteger>& nestedList) {
    int ans = DFSdepthSum(nestedList, 1);;
    return ans;
}