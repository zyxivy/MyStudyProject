//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//[
//	"((()))",
//	"(()())",
//	"(())()",
//	"()(())",
//	"()()()"
//]

#include "pch.h";

void build(int left, int right, string curStr, vector<string>& result) 
{
	if (left == 0 && right == 0) {
		result.push_back(curStr);
		return;
	}
	if (left > 0) {
		build(left - 1, right + 1, curStr + "(", result);
	}
	if (right > 0) {
		build(left, right - 1, curStr + ")", result);
	}
}
vector<string> Solution::generateParenthesis(int n) {
	vector<string> result;
	string curstr = "";
	build(n, 0, curstr, result);
	return result;
}