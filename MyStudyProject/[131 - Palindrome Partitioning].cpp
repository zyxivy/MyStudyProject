//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return all possible palindrome partitioning of s.
//For example, given s = "aab",
//Return
//[
//    ["aa", "b"],
//    ["a", "a", "b"]
//]

#include "Header.h";

bool isPalindrome(string s, int i, int j) {
	if (i > j) {
		return false;
	}
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

void findPalindrome(vector<string> &strs, vector<vector<string>> &result, int start, string s) {
	if (start >= s.length()) {
		result.push_back(strs);
	}
	else {
		for (int i = start; i < s.length(); i++) {
			if (isPalindrome(s, start, i)) {
				strs.push_back(s.substr(start, i - start + 1));
				findPalindrome(strs, result, i + 1, s);
				strs.pop_back();
			}
		}
	}
}

vector<vector<string>> Solution::PalindromePartition(string s) {
	vector<vector<string>> result;
	vector<string> strs;
	findPalindrome(strs, result, 0, s);
	return result;
}
