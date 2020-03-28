//Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.
//
//
//
//Example:
//
//Input: "23"
//	Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//	Note :
//
//	Although the above answer is in lexicographical order, your answer could be in any order you want.

#include "pch.h";

vector<string> table = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void BuildLetters(string digits, int startPos, vector<string>& result, string curLetter) {
	if (startPos == digits.length()) {
		result.push_back(curLetter);
		return;
	}
	for (int i = 0; i < table[digits[startPos]-'0'].length(); i++) {
		curLetter += table[digits[startPos] -'0'][i];
		BuildLetters(digits, startPos + 1, result, curLetter);
		curLetter.pop_back();
	}
}
vector<string> Solution::letterCombinations(string digits)
{
	vector<string> result;

	if (digits.empty()) {
		return result;
	}

	string curLetter = "";
	BuildLetters(digits, 0, result, curLetter);
	return result;
}
