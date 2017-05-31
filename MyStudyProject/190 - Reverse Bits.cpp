//Reverse bits of a given 32 bits unsigned integer.
//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//Follow up :
//If this function is called many times, how would you optimize it ?

#include "Header.h";
uint32_t Solution::reverseBits(uint32_t n) {
    uint32_t res = 0;
    uint32_t mask = 1;
    for (int i = 0; i<32; i++) {
        if (n&mask) res = res + 1;
        if (i != 31) res <<= 1;
        mask <<= 1;
    }
    return res;
}