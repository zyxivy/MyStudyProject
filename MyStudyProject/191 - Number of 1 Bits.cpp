//Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//For example, the 32 - bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

#include "Header.h";
int Solution::hammingWeight(uint32_t n) {
    int count = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if (n&mask) count++;
        mask <<= 1;
    }
    return count;
}