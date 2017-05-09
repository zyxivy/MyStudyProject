//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.
//
//For example, given n = 2, return[0, 1, 3, 2].Its gray code sequence is :
//
//00 - 0
//01 - 1
//11 - 3
//10 - 2
//Note :
//    For a given n, a gray code sequence is not uniquely defined.
//
//    For example, [0, 2, 3, 1] is also a valid gray code sequence according to the above definition.
//
//    For now, the judge is able to judge based on one instance of gray code sequence.Sorry about that.
#include "Header.h";

//n-bit Gray Codes can be generated from list of (n-1)-bit Gray codes using following steps.
//1) Let the list of(n - 1) - bit Gray codes be L1.Create another list L2 which is reverse of L1.
//2) Modify the list L1 by prefixing a ‘0’ in all codes of L1.
//3) Modify the list L2 by prefixing a ‘1’ in all codes of L2.
//4) Concatenate L1 and L2.The concatenated list is required list of n - bit Gray codes.

vector<int> grayCode(int n) {
    vector<int> result;
    int k = 0;
    result.push_back(0);
    for (int i = 0;i < n;i++) {
        int offset = 1 << i;
        vector<int> reverse;
        for (int j = result.size() - 1;j >= 0;j--) {
            result.push_back(result[j] + offset);
        }
    }
    return result;
}
