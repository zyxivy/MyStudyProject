//Given a string s, find the length of the longest substring T that contains at most k distinct characters.
//Example
//For example, Given s = "eceba", k = 3,
//T is "eceb" which its length is 4.
//Challenge
//O(n), n is the size of the string s.
//Tags
//String Two Pointers LintCode Copyright Hash Table
//Related Problems
//Medium Longest Substring Without Repeating Characters

#include "Header.h";
int Solution::lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k == 0) return 0;

    map<char, int> hmap;
    int left = 0, result = 0;

    for (int right = 0; right<s.length(); right++) {
        hmap[s[right]]++;

        while (left < right && hmap.size() > k) {
            hmap[s[left]]--;
            if (hmap[s[left]] == 0)
                hmap.erase(s[left]);
            left++;
        }

        result = max(result, right - left + 1);
    }

    return result;
}