//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.

#include "Header.h";

int Solution::divide(int dividend, int divisor) {
    if (divisor == 0) {
        return dividend<0?INT_MIN:INT_MAX;
    }
    if (abs(divisor) == 1) {
        if (dividend == INT_MIN && divisor==-1) {
            return INT_MAX;
        }
        return divisor == -1 ? -dividend : dividend;
    }
    unsigned long long dvd = abs((long long)dividend);
    unsigned long long dvs = abs((long long)divisor);
    int ret = 0;

    while (dvd >= dvs) {
        int count = 0;
        while (dvd >= (dvs << count)) {
            count++;
        }
        ret += (1 << (count - 1));
        dvd -= (dvs << (count - 1));
    }
    if ((dividend < 0 && divisor > 0) || (dividend>0 && divisor<0)) {
        ret = -ret;
    }
    return ret;
}