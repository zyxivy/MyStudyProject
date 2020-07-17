//Given a string sand a string t, check if s is subsequence of t.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
//
//Follow up :
//If there are lots of incoming S, say S1, S2, ..., Sk where k >= 1B, and you want to check one by one to see if T has its subsequence.In this scenario, how would you change your code ?
//
//Credits :
//	Special thanks to @pbrother for adding this problemand creating all test cases.
//
//
//
//	Example 1:
//
//Input: s = "abc", t = "ahbgdc"
//Output : true
//Example 2 :
//
//	Input : s = "axc", t = "ahbgdc"
//	Output : false
//
//
//	Constraints :
//
//	0 <= s.length <= 100
//	0 <= t.length <= 10 ^ 4
//	Both strings consists only of lowercase characters.

#include "pch.h";
bool isSubsequence(string s, string t) {
	int i = 0; j = 0;
	while (i < s.size() && j < t.size()) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	return i == s.size();
}

bool isSubsequenceBinarySearch(string s, string t) {
	// setup t char index map
	unordered_map<char, vector<int>> mp;
	for (int i = 0; i < t.length();i++) {
		mp[t[i]].push_back(i);
	}

	int tPos = -1; // track the index of previously matched char in t
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (mp.find(c) != mp.end()) {
			vector<int> v = mp[c];
			vector<int>::iterator iter = upper_bound(v.begin(), v.end(), tPos);
			if (iter == v.end()) {
				return false;
			}
			tPos = *iter;
		}
		else {
			return false;
		}
	}
	return true;
}

