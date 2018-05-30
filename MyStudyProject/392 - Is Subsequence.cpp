//Given a string s and a string t, check if s is subsequence of t.
//You may assume that there is only lower case English letters in both s and t.t is potentially a very long(length ~= 500, 000) string, and s is a short string(<= 100).
//A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
//Example 1:
//	s = "abc", t = "ahbgdc"
//		Return true.
//		Example 2 :
//		s = "axc", t = "ahbgdc"
//		Return false.
//		Follow up :
//	If there are lots of incoming S, say S1, S2, ..., Sk where k >= 1B, and you want to check one by one to see if T has its subsequence.In this scenario, how would you change your code ?

#include "Header.h";
int binarySearchIsSubsequence(int target, vector<int> v, int start, int end) {
	if (start > end) {
		return -1;
	}
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (v[mid] == target) {
			return mid;
		}
		else if (v[mid] < target) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	return -1;
}
bool isSubsequence(string s, string t) {
	if (s.empty())
		return true;

	map<char, vector<int>> mp;
	for (int i = 0; i < t.length(); i++) {
		vector<int> v;
		if (mp.find(t[i]) != mp.end()) {
			v = mp[t[i]];
		}
		v.push_back(i);
		mp[t[i]] = v;
	}

	int prev = -1;
	for (int i = 0; i < s.length(); i++) {
		if (mp.find(s[i]) == mp.end()) {
			return false;
		}
		vector<int> v = mp[s[i]] ;
		prev = binarySearchIsSubsequence(prev, v, 0, v.size() - 1);
		if (prev == -1) {
			return false;
		}
		prev++;
	}
	return true;

}