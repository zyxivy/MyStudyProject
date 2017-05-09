//Given two binary strings, return their sum(also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

#include "Header.h";
string Solution::addBinary(string a, string b) {
    if (a.length() == 0) {
        return b;
    }
    if (b.length() == 0) {
        return a;
    }
    string s = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while (i >= 0 && j >= 0) {
        s.insert(0, 1, '0'+((a[i]-'0' + b[j] - '0' +carry) % 2));
        carry = (a[i] - '0' + b[j] - '0' + carry) / 2;
        i--;
        j--;
    }
    while (i >= 0) {
        s.insert(0, 1, '0' + ((a[i] - '0' + carry) % 2));
        carry = (a[i] - '0' + carry) / 2;
        i--;
    }
    while (j >= 0) {
        s.insert(0, 1, '0' + ((b[j] - '0' + carry) % 2));
        carry = (b[j] - '0' + carry) / 2;
        j--;
    }
    if (carry != 0) {
        s.insert(0, 1, '0' + carry);
    }
    return s;
}