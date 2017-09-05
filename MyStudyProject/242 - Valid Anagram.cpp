//Given two strings s and t, write a function to determine if t is an anagram of s.
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//Note:
//You may assume the string contains only lowercase alphabets.
//Follow up :
//What if the inputs contain unicode characters ? How would you adapt your solution to such case ?
#include "Header.h";
bool Solution::isAnagram(string s, string t) {
    vector<int> charcount(26, 0);
    if (s.length()!= t.length()) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        charcount[s[i] - 'a']++; 
        charcount[t[i] - 'a']--;
    }
    for (int i = 0; i < charcount.size(); i++) {
        if (charcount[i] != 0) {
            return false;
        }
    }
    return true;
}