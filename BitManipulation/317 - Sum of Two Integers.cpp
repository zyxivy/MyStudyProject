//Calculate the sum of two integers aand b, but you are not allowed to use the operator + and -.
//
//Example 1:
//
//Input: a = 1, b = 2
//Output : 3
//Example 2 :
//
//	Input : a = -2, b = 3
//	Output : 1

#include "pch.h";

// XOR is add without carry
// AND is carry
// continue until carry is 0
// cast carry to unsigned int to take care of negative numbers.
int getSum(int a, int b) {
    int c;
    while (b != 0) {
        c = (a & b);
        a = a ^ b;
        b = (unsigned int)(c) << 1;
    }
    return a;
}