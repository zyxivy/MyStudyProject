//Implement a basic calculator to evaluate a simple expression string.
//The expression string contains only non - negative integers, +, -, *, / operators and empty spaces.The integer division should truncate toward zero.
//You may assume that the given expression is always valid.
//Some examples :
//"3+2*2" = 7
//" 3/2 " = 1
//" 3+5 / 2 " = 5
//
//Note : Do not use the eval built - in library function.

#include "Header.h";
bool isNumber(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
}
bool isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int Solution::calculateII(string s) {
    int md = 0; //-1 for *, 0 for +/-, 1 for /
    int sign = 1; //-1 for +, 1 for -
    int prev = 0;
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isNumber(c)) {
            int num = s[i] - '0';
            while (++i < s.length() && isNumber(s[i])) {
                num = num * 10 + s[i] - '0';
            }
            i--;

            if (md == -1) {
                prev = prev*num;
                md = 0;
            }
            else if (md == 1) {
                prev = prev / num;
                md = 0;
            }
            else {
                prev = num;
            }
        }
        else if (c == '/') {
            md = 1;
        }
        else if (c == '*') {
            md = -1;
        }
        else if (c == '+') {
            result = result + sign*prev;
            sign = 1;
        }
        else if (c == '-') {
            result = result + sign*prev;
            sign = -1;
        }
    }

    result = result + sign*prev;

    return result;
}