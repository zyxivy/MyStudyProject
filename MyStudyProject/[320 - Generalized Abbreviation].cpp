//Write a function to generate the generalized abbreviations of a word.
//Example:
//Given word = "word", return the following list(order does not matter) :
//    ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

#include "Header.h";
void backtrack(vector<string> ret, string word, int pos, string cur, int count) {
    if (pos == word.length()) {
        if (count > 0) 
            cur += to_string(count);
        ret.push_back(cur);
    }
    else {
        backtrack(ret, word, pos + 1, cur, count + 1);
        backtrack(ret, word, pos + 1, cur + (count>0 ? to_string(count) : "") + word[pos], 0);
    }
}
vector<string> Solution::generateAbbreviations(string word) {
    vector<string> ret;
    backtrack(ret, word, 0, "", 0);

    return ret;
}