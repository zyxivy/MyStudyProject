
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty ? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.

#include "Header.h";

bool isAlphaNumeric(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
bool Solution::isPalindrome(string s) {
    bool ret = true;
    int l = 0;
    int r = s.length() - 1;
    if (s.length() == 0)
        return true;
    while (l < r) {

        if (!isAlphaNumeric(s[l])) {
            l++;
            continue;
        }
        if (!isAlphaNumeric(s[r])) {
            r--;
            continue;
        }
        if (s[l] >= 'A' && s[l] <= 'Z') {
            s[l] += 32;
        }
        if (s[r] >= 'A' && s[r] <= 'Z') {
            s[r] += 32;
        }
        if (s[l] != s[r]) {
            ret = false;
            break;
        }
        l++;
        r--;
    }

    return ret;
}