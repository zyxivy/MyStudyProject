
//Follow up for H - Index: What if the citations array is sorted in ascending order ? Could you optimize your algorithm ?
//Hint:
//Expected runtime complexity is in O(log n) and the input is sorted.


#include "Header.h";
int Solution::hIndexII(vector<int>& citations) {
    int len = citations.size();
    if (len == 0) {
        return 0;
    }

    if (citations[0] >= len) {
        return len;
    }
    int l = 0;
    int r = len - 1;
    int m = 0;
    while (l <= r) {
        m = (r + l) / 2;
        if (citations[m] == len - m) {
            return len - m;
        }
        if (citations[m] < len - m) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return len - r - 1;
}