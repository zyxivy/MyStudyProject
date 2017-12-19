//Given an integer array nums, find the sum of the elements between indices i and j(i ≤ j), inclusive.
//The update(i, val) function modifies nums by updating the element at index i to val.
//Example:
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//
//Note :
//    The array is only modifiable by the update function.
//    You may assume the number of calls to update and sumRange function is distributed evenly.

#include "Header.h";
//http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

class NumArray {
private:
    int n;// size of input nums
    vector<int> m_nums;
    vector<int> BITree; //BITree with size n+1;   

                        // Updates a node in Binary Index Tree (BITree) at given index
                        // in BITree.  The given value 'val' is added to BITree[i] and 
                        // all of its ancestors in tree.
    void updateBIT(int index, int val) {
        // index in BITree[] is 1 more than the index in arr[]
        index = index + 1;

        // Traverse all ancestors and add 'val'
        while (index <= n)
        {
            // Add 'val' to current node of BI Tree
            BITree[index] += val;

            // Update index to that of parent in update View
            index += index & (-index);
        }
    }

    int getSum(int index) {
        int sum = 0; // Iniialize result

                     // index in BITree[] is 1 more than the index in arr[]
        index = index + 1;

        // Traverse ancestors of BITree[index]
        while (index>0)
        {
            // Add current element of BITree to sum
            sum += BITree[index];

            // Move index to parent node in getSum View
            index -= index & (-index);
        }
        return sum;
    }

public:
    NumArray(vector<int> nums) {
        // Create and initialize BITree[] as 0
        n = nums.size();
        m_nums.resize(n);
        BITree.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            m_nums[i - 1] = nums[i - 1];
            BITree[i] = 0;
        }

        // Store the actual values in BITree[] using update()
        for (int i = 0; i<n; i++)
            updateBIT(i, nums[i]);
    }

    void update(int i, int val) {
        updateBIT(i, val - m_nums[i]);
        m_nums[i] = val;
    }

    int sumRange(int i, int j) {
        int s1 = getSum(j);
        if (i == 0) {
            return s1;
        }
        int s2 = getSum(i - 1);
        return s1 - s2;
    }
};

//https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
//https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

//int main() {
//    NumArray na({ 1, 2, 3, 4, 5, 6, 7 });
//    int s = 0;
//    s = na.sumRange(0, 2);
//    na.update(2, 10);
//    s = na.sumRange(0, 2);
//    return s;
//}