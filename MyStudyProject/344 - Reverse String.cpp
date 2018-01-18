//Write a function that takes a string as input and returns the string reversed.
//Example:
//Given s = "hello", return "olleh".
#include "Header.h";
string Solution::reverseString(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        swap(s[i++], s[j--]);
    }
    return s;
}