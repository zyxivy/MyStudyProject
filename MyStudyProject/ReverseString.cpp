//Write a function that reverses a string.The input string is given as an array of characters char[].
//
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
//
//You may assume all the characters consist of printable ascii characters.
//
//
//
//Example 1:
//
//Input: ["h", "e", "l", "l", "o"]
//	Output : ["o", "l", "l", "e", "h"]
//	Example 2 :
//
//	Input : ["H", "a", "n", "n", "a", "h"]
//	Output : ["h", "a", "n", "n", "a", "H"]

#include "Header.h";

void reverseHelper(vector<char>& s, int length, int i, int j) {
	if (i >= j) {
		return;
	}
	reverseHelper(s, s.size(), i + 1, j - 1);
	char c = s[i];
	s[i] = s[j];
	s[j] = c;
}
void Solution::reverseStringRecursive(vector<char>& s) {
	reverseHelper(s, s.size(), 0, s.size() - 1);
	int i = s.size();
	i++;
}