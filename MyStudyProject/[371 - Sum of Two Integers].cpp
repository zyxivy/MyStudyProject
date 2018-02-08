//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//Example:
//Given a = 1 and b = 2, return 3.

#include "Header.h";
//https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
int Solution::getSum(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

int getSubtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }

    return a;
}