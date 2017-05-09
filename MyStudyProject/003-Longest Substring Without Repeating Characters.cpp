//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#include "Header.h"

int Solution::lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int cur_len = 0;
        int max_len = 0;

        int dictTable[128];
        for (int k = 0;k < 128;k++) {
            dictTable[k] = 0;
        }
        for (i = 0;i < s.length();) {
            dictTable[s[i]] = 1;
            j = i + 1;
            while (j < s.length())
            {
                if (dictTable[s[j]] == 0)
                {
                    dictTable[s[j]] = 1;
                    j++;
                }
                else {
                    for (int k = 0;k < 128;k++) {
                        dictTable[k] = 0;
                    }
                    break;
                }
            }
            max_len = (j - i > max_len) ? j - i : max_len;
        }
        return max_len;
    }

