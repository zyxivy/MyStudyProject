//Write a function to find the longest common prefix string amongst an array of strings.

#include "Header.h"

string Solution::longestCommonPrefix(vector<string>& strs) {
    char ch;
    string ret="";
    bool ended = false;
    if (strs.size() > 0) {
        for (int i = 0;;i++) {
            if (i < strs[0].length()) {
                ch = strs[0][i];
                for (int j = 1;j < strs.size();j++) {
                    if (i < strs[j].length()) {
                        if (ch != strs[j][i])
                        {
                            ended = true;
                            break;
                        }
                    }
                    else {
                        ended = true;
                        break;
                    }
                }
            }
            else {
                ended = true;
            }

            if (ended) {
                break;;
            }
            ret += ch;
        }
    }

    return ret;
}