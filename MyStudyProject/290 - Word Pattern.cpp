//Given a pattern and a string str, find if str follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.
//Examples:
//pattern = "abba", str = "dog cat cat dog" should return true.
//pattern = "abba", str = "dog cat cat fish" should return false.
//pattern = "aaaa", str = "dog cat cat dog" should return false.
//pattern = "abba", str = "dog dog dog dog" should return false.
//
//Notes :
//    You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

#include "Header.h";
bool wordPattern(string pattern, string str) {
    if (pattern == "" || str == "") {
        return false;
    }
    map<char, string> mp;
    map<string, char> mp2;
    vector<string> strs;

    int i = 0;
    int start = 0;
    int found = 0;
    while (start < str.length() && i < pattern.length()) {
        found = start + 1;
        while (found < str.length()) {
            if (str[found] != ' ') {
                found++;
            }
            else {
                break;
            }
        }
        string s = str.substr(start, found - start);
        if (mp.find(pattern[i]) == mp.end() && mp2.find(s) == mp2.end()) {
            mp[pattern[i]] = s;
            mp2[s] = pattern[i];
        }
        else if (mp.find(pattern[i]) != mp.end() && mp2.find(s) != mp2.end()) {
            if (mp[pattern[i]] != s || mp2[s] != pattern[i]) {
                return false;
            }            
        }
        else {
            return false;
        }
        i++;
        start = found + 1;
    }
    if (i < pattern.length() || found < str.length()) {
        return false;
    }
    return true;
}
