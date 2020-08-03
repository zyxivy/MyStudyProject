//Given a word, you need to judge whether the usage of capitals in it is right or not.
//
//We define the usage of capitals in a word to be right when one of the following cases holds :
//
//All letters in this word are capitals, like "USA".
//All letters in this word are not capitals, like "leetcode".
//Only the first letter in this word is capital, like "Google".
//Otherwise, we define that this word doesn't use capitals in a right way.
//
//
//Example 1:
//
//Input: "USA"
//Output : True
//
//
//Example 2 :
//
//	Input : "FlaG"
//	Output : False


#include "pch.h";
bool isCapital(char c) {
	return 'A' <= c && c <= 'Z';
}
bool detectCapitalUse(string word) {
	int n = word.length();

	if (word.empty()) {
		return false;
	}

	bool firstCap = isCapital(word[0]);

	if (n == 1) {
		return firstCap;
	}

	bool secondCap = isCapital(word[1]);
	if (!firstCap && secondCap) {
		return false;
	}

	for (int i = 2; i < n; i++) {
		if (isCapital(word[i]) && !secondCap) {
			return false;
		}
	}

	return true;
}