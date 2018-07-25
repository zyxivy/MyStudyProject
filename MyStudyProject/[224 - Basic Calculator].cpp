//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open(and closing parentheses), the plus + or minus sign - , non - negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples :
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
//Note : Do not use the eval built - in library function.

#include "Header.h";

bool calculateisDigit(char c) {
	return c >= '0'&& c <= '9';
}
int Solution::calculate(string s) {
	int ans = 0;
	stack<int> nums, ops;
	int sign = 1;
	int n = 0;
	for (int i = 0; i < s.length();i++) {
		char c = s[i];
		if (calculateisDigit(c)) {
			n = n * 10 + c - '0';
		}
		else {
			ans += sign * n;
			n = 0;
			if (c == '-') {
				sign = -1;
			}
			if (c == '+') {
				sign = 1;
			}
			if (c == '(') {
				nums.push(ans);
				ops.push(sign);
				ans = 0;
				sign = 1;
			}
			if (c == ')' && !ops.empty()) {
				ans = nums.top() + ans * ops.top();
				nums.pop();
				ops.pop();
			}
		}
	}
	ans += sign * n;
    return ans;
}