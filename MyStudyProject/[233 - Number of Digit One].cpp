//Given an integer n, count the total number of digit 1 appearing in all non - negative integers less than or equal to n.
//For example :
//Given n = 13,
//Return 6, because digit 1 occurred in the following numbers : 1, 10, 11, 12, 13.

#include "Header.h";

//http://yucoding.blogspot.com/2015/12/leetcode-question-number-of-digit-one.html
int Solution::countDigitOne(int n) {
    int res = 0;
    int m = 0;
    for (long i = 1; i <= n; i = i * 10) {
        int d = n % (i * 10) / i;
        res += d*m + (d == 1)*(n%i + 1) + (d>1)*(i);
        m = m * 10 + i;
    }
    return res;
}