//Given two strings S and T, determine if they are both one edit distance apart

#include "Header.h";
bool Solution::oneEditDistance(string word1, string word2) {
    int s1 = word1.length();
    int s2 = word2.length();
    if ((s1 < s2 && s1 + 1 != s2) || (s1 > s2 && s1 - 1 != s2)) {
        return false;
    }

    if (s1 < s2) {
        string tmp;
        for (int i = 0; i < s2; i++) {
            tmp = word2.substr(0, i) + word2.substr(i + 1, s2 - i - 1);
            if (tmp == word1) {
                return true;
            }
        }
    }
    else if (s1 > s2) {
        string tmp;
        for (int i = 0; i < s1; i++) {
            tmp = word1.substr(0, i) + word1.substr(i + 1, s1 - i - 1);
            if (tmp == word2) {
                return true;
            }
        }
    }
    else {
        bool diff = false;
        for (int i = 0; i < s1; i++) {
            if (word1[i] != word2[i]) {
                if (diff) {
                    return false;
                }
                diff = true;
            }
        }
    }
    return true;
}