//Given an array of words and a length L, format the text such that each line has exactly L characters and is fully(left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line.Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//
//Extra spaces between words should be distributed as evenly as possible.If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left justified and no extra space is inserted between words.
//
//For example,
//words: ["This", "is", "an", "example", "of", "text", "justification."]
//    L : 16.
//
//    Return the formatted lines as :
//[
//    "This    is    an",
//    "example  of text",
//    "justification.  "
//]
//Note : Each word is guaranteed not to exceed L in length.
//
//    click to show corner cases.
//
//    Corner Cases :
//       A line other than the last line might contain only one word.What should you do in this case ?
//           In this case, that line should be left - justified.

#include "Header.h";
vector<string> Solution::fullJustify(vector<string>& words, int maxWidth) {
    int L = maxWidth;
    vector<string> ret;
    int i = 0;
    if (L == 0) {
        ret.push_back("");
        return ret;
    }
    while (i < words.size()) {
        string str = "";
        while (i < words.size()) {
            if ((str + words[i]).length() + 1 < L) {
                str += words[i] + " ";
                i++;
            }
            else if ((str + words[i]).length() == L) {
                str += words[i];
                ret.push_back(str);
                str = "";
                i++;
                break;
            }
            else if ((str + words[i]).length() + 1 == L) {
                str += words[i];
                int pos=str.find_first_of(' ', 0);
                if (pos != string::npos) {
                    str.insert(pos, 1, ' ');
                }
                else {
                    str.append(L - str.length(), ' ');
                }
                ret.push_back(str);
                str = "";
                i++;
                break;
            }
            else {
                if (str[str.length() - 1] == ' ') {
                    str.pop_back();
                }
                if (str.length() < L) {
                    if (str.find_first_of(' ', 0) == string::npos) {
                        str.append(L - str.length(), ' ');
                    }
                    else {
                        int pos = 0;
                        int n = L - str.length();
                        int j = 0;
                        while(j<n) {
                            if (str[pos] == ' ') {
                                pos++;
                            }
                            else {
                                pos = str.find_first_of(' ', pos + 1);
                                if (pos != string::npos) {
                                    str.insert(pos, 1, ' ');
                                    j++;
                                }
                                else {
                                    pos = 0;
                                }
                            }                            
                        }
                    }
                }
                ret.push_back(str);
                str = "";
                break;
            }
        }
        if (str != "") {
            str.append(L - str.length(), ' ');
            ret.push_back(str);
            str = "";
            i++;
        }
    }
    return ret;
}