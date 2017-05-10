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
    string::iterator i = s.begin();
    string::iterator j = s.end()-1;

    while (i < j) {
        string::iterator i1 = i;
        string::iterator i2 = i;

        string::iterator j1 = j;
        string::iterator j2 = j;

        while (*i1 == ' ') {
            i1++;
            i2 = i1;
        }

        while (*j2 == ' ') {
            j2--;
            j1 = j2;
        }

        if (*i1 != ' ' && *j2 != ' ') {
            while (*i2 != ' ') {
                i2++;
            }
            while (*j1 != ' ') {
                j1--;
            }

            if (i2 <= j1) {
                string word1 = s.substr(i1 - s.begin(), i2 - i1);
                string word2 = s.substr(j1 - s.begin() + 1, j2 - j1);
                s.erase(j1+1, j+1);
                s.insert(j1 + 1, word1.begin(), word1.end());
                //s.insert(j1 + 1, ' ');
                
                s.erase(i, i2);
                s.insert(i, word2.begin(), word2.end());

                if (word2.length() > (i2 - i)) {
                    j = j1 + word2.length() - (i2 - i) + 1;
                }
                else {
                    j = j1 - ((i2 - i)-word2.length()  ) + 1;
                }

                i = i2 + word2.length() - (i2 - i) + 1;
            }

        }

    }
    s = s + "";
}