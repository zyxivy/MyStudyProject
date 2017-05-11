//Given an input string, reverse the string word by word.
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//Update(2015 - 02 - 12) :
//    For C programmers : Try to solve it in - place in O(1) space.
//    click to show clarification.
//    Clarification :
//
//    What constitutes a word ?
//    A sequence of non - space characters constitutes a word.
//    Could the input string contain leading or trailing spaces ?
//    Yes.However, your reversed string should not contain leading or trailing spaces.
//    How about multiple spaces between two words ?
//    Reduce them to a single space in the reversed string.

#include "Header.h";
void Solution::reverseWords(string &s) {
    int i = 0;
    while (i < s.length() && s[i] == ' ') {
        i++;
    }
    if (i > 0) {
        s.erase(0, i);
    }

    int j = s.length() - 1;
    while (j >= 0 && s[j] == ' ') {
        j--;
    }
    if (j<s.length() - 1) {
        s.erase(j+1, s.length() - 1-j);
    }

    i = 0;
    j = s.length() - 1;
    while (i < j) {
        int i1 = i;
        int i2 = i;

        int j1 = j;
        int j2 = j;

        while (i1 < s.length() && s[i1] == ' ') {
            i1++;
            i2 = i1;
        }

        while (j2 >= 0 && s[j2] == ' ') {
            j2--;
            j1 = j2;
        }

        if (i1 > j2) {
            s.erase(i, j - i);
            break;
        }

        if (s[i1] != ' ' && s[j2] != ' ') {
            while (s[i2] != ' ') {
                i2++;
            }
            while (s[j1] != ' ') {
                j1--;
            }

            if (i2 <= j1) {
                bool bi = s[i] == ' ';
                bool bj = s[j] == ' ';

                string word1 = s.substr(i1, i2 - i1);
                string word2 = s.substr(j1+1, j2 - j1);

                s.erase(j1 + 1, j - j1);
                if (bj) {
                    s.insert(j1 + 1, word1+" ");
                }
                else
                {
                    s.insert(j1 + 1, word1);
                }

                s.erase(i, i2 - i);
                j1 = j1 - (i2 - i);
                i2 = i2 - (i2 - i);
                if (bi) {
                    s.insert(i2, " "+word2);
                    j1 = j1 + word2.length()+1;
                    i2 = i2 + word2.length()+1;
                }
                else {
                    s.insert(i2, word2);
                    j1 = j1 + word2.length();
                    i2 = i2 + word2.length();
                }

                i = i2;
                j = j1;
            }
            else {
                if (i < i1 - 1) {
                    s.erase(i, i1-i-1);
                }
                if (j > j2 + 1) {
                    s.erase(j2+1, j - j2 - 1);
                }
                break;
            }
        }

    }
    s = s + "";
}