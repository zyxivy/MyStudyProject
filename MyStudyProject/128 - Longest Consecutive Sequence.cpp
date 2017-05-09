//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//For example,
//Given[100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.
//Your algorithm should run in O(n) complexity.


#include "Header.h"

int Solution::longestConsecutive(vector<int>& nums) {
    int longest = 1;
    if (nums.size() <= 1) {
        return nums.size();
    }

    set<int> st;

    for (int i = 0;i < nums.size(); i++) {
        st.insert(nums[i]);
    }

    for (int i = 0;i < nums.size();i++) {
        int curNum = nums[i];
        int curLen = 1;

        curNum++;
        while (st.find(curNum) != st.end()) {
            st.erase(curNum);
            curNum++;
            curLen++;
        }

        curNum = nums[i] - 1;
        while (st.find(curNum) != st.end()) {
            st.erase(curNum);
            curNum--;
            curLen++;
        }

        longest = curLen >= longest ? curLen : longest;
    }
    return longest;
}