#include "Header.h"

string Solution::ZigZagConvert(string s, int numRows) {

    if (numRows == 1 || s.length()==1) {
        return s;
    }
    string ret;
    for (int i = 0;i < numRows;i++) {
        if (i == 0 || i == numRows - 1) {
            int j = 0;
            while (j*(2 * numRows - 2) + i >= 0 && j*(2 * numRows - 2) + i < s.length()) {
                ret += s[j*(2 * numRows - 2) + i];
                j++;
            }
        }
        else {    
            if(i<s.length())
                ret += s[i];
            int j = 1;
            while (j*(2 * numRows - 2) + i < s.length() || j*(2 * numRows - 2) - i < s.length())
            {
                if (j*(2 * numRows - 2) - i >= 0 && j*(2 * numRows - 2) - i< s.length()) {
                    ret += s[j*(2 * numRows - 2) - i];
                }
                if (j*(2 * numRows - 2) + i >= 0 && j*(2 * numRows - 2) + i < s.length()) {
                    ret += s[j*(2 * numRows - 2) + i];
                }
                j++;
            }
        }
    }
    return ret;
}