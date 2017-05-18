//Given an integer n, return the number of trailing zeroes in n!.
//Note: Your solution should be in logarithmic time complexity.

#include "Header.h";

//https://en.wikipedia.org/wiki/Trailing_zero

int Solution::trailingZeroes(int n) {
    if (n < 0) {
        return -1;
    }
    int num = 0;
    double logn = log(n);
    double log5 = log(5);
    int k = (int)(logn / log5);
    for (int i = 1; i < k+1; i++) {
        int fives = 1;
        for (int j = 0; j < i; j++) {
            fives *= 5;
        }
        num += n / fives;
    }
    return num;
}


//http://bookshadow.com/weblog/2014/12/30/leetcode-factorial-trailing-zeroes/
//http://yucoding.blogspot.com/2015/10/leetcode-question-factorial-trailing.html
int trailingZeroes(int n) {
    if (n < 0) {
        return -1;
    }
    int num = 0;
    long x = 5;
    while (n >= x) {
        num += n / x;;
        x *= 5;
    }
    return num;
}