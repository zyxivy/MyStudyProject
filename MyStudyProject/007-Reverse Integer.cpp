//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//    Example2 : x = -123, return -321

#include "Header.h"

int Solution::reverseInteger(int x) {
    int n = 0;
    int t = 0;
    int i = x;

    bool flag = false;
    if (x < 0) {
        x = -x;
        flag = true;
    }
    while (x > 0) {
        t = n * 10 + x % 10;
        x /= 10;
        if ((n >= 214748364 && x>7) || n > 214748364) {
            n = 0;
            break;
        }
        n = t;
    }
    n = flag == true ? -n : n;
    return n;
}

