//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//    For example,
//    Given s = "Hello World",
//    return 5.

#include "Header.h";
int Solution::lengthOfLastWord(string s) {
    int i = s.length()-1;
    int lastWord = -1;
    while (i >=0) {
        if (s[i] != ' ' && lastWord==-1) {
            lastWord = i;
        }
        else if (s[i] == ' '&&lastWord != -1) {
            return lastWord - i;
        }
        i--;
    }
    if (lastWord == -1) {
        return 0;
    }
    return lastWord + 1;
}