//Given a range[m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//For example, given the range[5, 7], you should return 4.

#include "Header.h";

int Solution::rangeBitwiseAnd(int m, int n) {
    int k = 0;
    while (n > 0 && m > 0 && n > m) {
        k++;
        m = m >> 1;
        n = n >> 1;
    }
    int result = m << k;
    return result;
}