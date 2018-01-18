//Given a nested list of integers, implement an iterator to flatten it.
//Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//Example 1:
//Given the list[[1, 1], 2, [1, 1]],
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be : [1, 1, 2, 1, 1].
//
//Example 2 :
//    Given the list[1, [4, [6]]],
//    By calling next repeatedly until hasNext returns false, the order of elements returned by next should be : [1, 4, 6].

#include "Header.h";
/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };
*/
class NestedIterator {
private:
    vector<int> nums;
    int pos = 0;
    void flatten(vector<NestedInteger> list, vector<int>& nums) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i].isInteger()) {
                nums.push_back(list[i].getInteger());
            }
            else {
                flatten(list[i].getList(), nums);
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &list) {
        flatten(list, nums);
    }

    int next() {
        if (pos < nums.size()) {
            return nums[pos];
        }
        return 0;
    }

    bool hasNext() {
        return pos < nums.size();
    }
};