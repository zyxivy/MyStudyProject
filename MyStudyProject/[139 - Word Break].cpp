//Given a non - empty string s and a dictionary wordDict containing a list of non - empty words, determine if s can be segmented into a space - separated sequence of one or more dictionary words.You may assume the dictionary does not contain duplicate words.
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//Return true because "leetcode" can be segmented as "leet code".
//UPDATE(2017 / 1 / 4) :
//    The wordDict parameter had been changed to a list of strings(instead of a set of strings).Please reload the code definition to get the latest changes.


//http://fisherlei.blogspot.com/2013/11/leetcode-word-break-solution.html

#include "Header.h";
bool Solution::wordBreak(string s, vector<string>& wordDict) {
    if (wordDict.empty()) {
        return false;
    }

    int len = s.length();

    set<string> list;
    for (int i = 0; i < wordDict.size(); i++) {
        list.insert(wordDict[i]);
    }
    
    vector<bool> possible (len+1, 0);
    possible[0] = true;
    for (int i = 0; i < len; i++) {
        for (int k = 0; k <= i; k++) {
            if (!possible[k])
                continue;
            possible[i+1] = possible[k] && list.find(s.substr(k, i - k+1)) != list.end();
            if (possible[i+1])
                break;
        }
    }

    return possible[len];
}