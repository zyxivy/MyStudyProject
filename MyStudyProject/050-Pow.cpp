//Implement pow(x, n).
#include "Header.h";

double power(double x, int n) {
    if (n == 1) {
        return x;
    }
    if (n == 0)
    {
        return 1;
    }
    int v = power(x, n / 2);
    if (n % 2 == 0) {
        return v*v;
    }
    else {
        return v*v*x;
    }
}

double Solution::myPow(double x, int n) {
    if (n < 0) {
        return 1 / power(x, -n);
    }
    else {
        return power(x, n);
    }
}