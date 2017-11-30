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
//https://www.topcoder.com/community/data-science/data-science-%20tutorials/binary-indexed-trees/
class NumArray {
private:
    vector<int> m_sum;
    vector<int> m_updates;
    vector<int> m_nums;
    int n = 0;
public:
    NumArray(vector<int> nums) {
        m_sum.push_back(nums[0]);
        nums.push_back(nums[0]);
        for (int i = 1; i < nums.size();i++) {
            m_sum.push_back(nums[i] + m_sum[i - 1]);
            m_nums.push_back(nums[i]);
        }
        n = nums.size();
        m_updates.resize(n);
    }

    void update(int i, int val) {
        m_updates[i] = val - m_nums[i];
    }

    int sumRange(int i, int j) {
        int ret = 0;
        int updates = 0;
        for (int p = i; p <= j; p++) {
            updates += m_updates[p];
        }
        if (i == 0) {
            ret = m_sum[j] + updates;
        }
        else {
            ret = m_sum[j] - m_sum[i - 1] + updates;
        }
        return ret;
    }
};

//https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
//https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

int main() {
    NumArray na({ 1,3,5 });
    int s = 0;
    s = na.sumRange(0, 2);
    na.update(1, 2);
    s = na.sumRange(0, 2);
    return s;
}