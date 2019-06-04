#include "pch.h";

// same with 209
// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
string minWindow(string s, string t) {
	vector<int> mp(128, 0);
	int counter = t.size();
	int begin = 0, end = 0, head = 0, d = INT_MAX;

	for (char c : t) {
		mp[c]++;
	}

	while (end < s.size()) {
		if (mp[s[end++]]-- > 0) {
			counter--;
		}

		while (counter == 0) {
			if (end - begin < d) {
				d = end - begin;
				head = begin;
			}
			
			if (mp[s[begin++]]++ == 0) {
				counter++;
			}
		}
	}
	return d == INT_MAX ? "" : s.substr(head, d);
}

int main() {
	minWindow("ADABECODEBANC", "ABC");
}