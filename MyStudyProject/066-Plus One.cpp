//Given a non - negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.
#include "Header.h";

vector<int> Solution::plusOne(vector<int>& digits) {
    int carry = 0;
    vector<int> ret;
    if (digits.size() > 0) {
        int carry = (digits[digits.size() - 1] + 1) / 10;
        ret.push_back((digits[digits.size() - 1] + 1) % 10);
        for (int i = digits.size() - 2;i >= 0;i--) {
            ret.insert(ret.begin(), (digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        if (carry != 0) {
            ret.insert(ret.begin(), carry);
        }
    }
    return ret;
}