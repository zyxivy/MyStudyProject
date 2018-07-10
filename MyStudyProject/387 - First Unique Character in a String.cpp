//Given a string, find the first non - repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples:
//
//s = "leetcode"
//return 0.
//
//s = "loveleetcode",
//return 2.
//Note: You may assume the string contain only lowercase letters.
#include "Header.h";
int Solution::firstUniqChar(string s) {
	if (s.length() == 0) {
		return -1;
	}
	unordered_map<char, int> mp;
	for (int i = 0; i < s.length();i++) {
		char c = s[i];
		if (mp.count(c) != 0) {
			mp[c] = INT_MAX;
		}
		else {
			mp[c] = i;
		}
	}
	int index = INT_MAX;
	for (auto m:mp) {
		index = min(index, m.second);
	}
	return index == INT_MAX ? -1 : index;
}