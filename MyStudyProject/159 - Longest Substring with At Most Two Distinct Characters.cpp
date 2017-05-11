//Given a string, find the longest substring that contains only two unique characters.For example, given "abcbbbbcccbdddadacb", 
//the longest substring that contains 2 unique character is "bcbbbbcccb".

#include "Header.h";

bool isNew(vector<char> st, char n) {
    for (int k = 0; k < st.size(); k++) {
        if (st[k] == n) {
            return false;
        }
    }
    return true;
}
int Solution::lengthOfLongestSubstringTwoDistinct(string s) {
    vector<char> st;
    if (s.length() <= 2){
        return s.length();
    }
    int i = 0;
    int j = 1;
    int newI = 0;
    int maxLen = 0;
    st.insert(st.begin(), s[0]);
    while (j < s.length()) {
        char c = s[j];
        if (isNew(st, c)) {
            st.insert(st.begin(), c);
            if (st.size() > 2) {
                st.pop_back();
                maxLen = maxLen > j - i ? maxLen : j - i;
                i = newI;
            }
            newI = j;
        }
        j++;
    }
    if (!isNew(st, s[j])) {
        maxLen = maxLen > j - i ? maxLen : j - i;
    }
    return maxLen;
}