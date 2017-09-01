//Given an integer, write a function to determine if it is a power of two.

#include "Header.h";

//If a number is power of 2, then its highly bit is 1 and there is only one 1. Therefore, n & (n - 1) is 0
bool Solution::isPowerOfTwo(int n) {
    return n > 0 && (n&(n - 1)) == 0;
}