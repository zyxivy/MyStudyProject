//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
//Subscribe to see which companies asked this question

#include "Header.h";

bool Solution::isValidParentheses(string s) {
    if (s.length() < 2 || s.length()%2 != 0) {
        return false;
    }
    vector<char> stack;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack.push_back(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.size() == 0) {
                return false;
            }
            char ch = stack[stack.size() - 1];
            if (!((ch == '('&&s[i] == ')') || (ch == '{'&&s[i] == '}') || (ch == '['&&s[i] == ']'))) {
                return false;
            }
            stack.pop_back();
        }
    }
    if (stack.size() == 0) {
        return true;
    }
    return false;
}