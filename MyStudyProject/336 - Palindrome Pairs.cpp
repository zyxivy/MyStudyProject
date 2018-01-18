//Given a list of unique words, find all pairs of distinct indices(i, j) in the given list, so that the concatenation of the two words, i.e.words[i] + words[j] is a palindrome.
//Example 1:
//Given words = ["bat", "tab", "cat"]
//Return[[0, 1], [1, 0]]
//The palindromes are["battab", "tabbat"]
//Example 2 :
//    Given words = ["abcd", "dcba", "lls", "s", "sssll"]
//    Return[[0, 1], [1, 0], [3, 2], [2, 4]]
//    The palindromes are["dcbaabcd", "abcddcba", "slls", "llssssll"]

#include "Header.h";
#include <bitset>
//https://leetcode.com/problems/palindrome-pairs/discuss/79215

bool isPalindromepalindromePairs(string str) {
    int i = 0;
    int j = str.size() - 1;

    while (i < j) {
        if (str[i++] != str[j--]) return false;
    }

    return true;
}
vector<vector<int>> Solution::palindromePairs(vector<string> words) {
    map<string, int> dict;
    vector<vector<int>> ans;
    // build dictionary
    for (int i = 0; i < words.size(); i++) {
        string key = words[i];
        reverse(key.begin(), key.end());
        dict[key] = i;
    }
    // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
    if (dict.find("") != dict.end()) {
        for (int i = 0; i < words.size(); i++) {
            if (i == dict[""]) continue;
            if (isPalindrome(words[i])) ans.push_back({ dict[""], i }); // 1) if self is palindrome, here ans covers concatenate("", self) 
        }
    }

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            string left = words[i].substr(0, j);
            string right = words[i].substr(j, words[i].size() - j);

            if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                ans.push_back({ i, dict[left] });     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
            }

            if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                ans.push_back({ dict[right], i });
            }
        }
    }

    return ans;
}