//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.
#include "Header.h";
//http://www.jiuzhang.com/solutions/interleaving-string/

bool Solution::isInterleave(string s1, string s2, string s3) {
    if (s3.length() != s1.length() + s2.length()) {
        return false;
    }
    if (s1.length() == 0) {
        return s2 == s3;
    }
    if (s2.length() == 0) {
        return s1 == s3;
    }
    int i = 0, j = 0, k = 0;
    int preI = -1, preJ = -1, preK=-1;
    while (k < s3.length() ) {
        if (i<s1.length() && j<s2.length() &&s1[i] == s3[k] && s2[j] == s3[k]) {
            if (preI == -1) {
                preI = i;
            }
            if (preJ == -1) {
                preJ = j;
            }
            if (preK = -1) {
                preK = k;
            }
            i++;
            j++;
            k++;
        }
        else if (i<s1.length()&&s1[i] == s3[k]) {
            if (j<s2.length()&&s2[j] != s3[k] && preJ != -1) {
                j = preJ;
                preJ = -1;
                preI = -1;
            }
            i++;
            k++;
        }        
        else if (j<s2.length()&&s2[j] == s3[k]) {
            if (i<s1.length()&&s1[i] != s3[k] && preI != -1) {
                i = preI;
                preI = -1;
                preJ = -1;
            }
            j++;
            k++;
        }
        else 
            break;
    }
    bool ret= (k == s3.length() && i == s1.length() && j == s2.length());
    return ret;
}