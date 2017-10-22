//Given a string s, return all the palindromic permutations(without duplicates) of it.
//Return an empty list if no palindromic permutation could be form.
//For example :
//Given s = "aabb", return["abba", "baab"].
//Given s = "abc", return[].

#include "Header.h";
//http://blog.csdn.net/sbitswc/article/details/51055153

void generatePalindromesDFS(int n , string ps, map<char,int>& mp, vector<string>& result) {
    if (ps.length() == n) {
        result.push_back(ps);
        return;
    }
    for (map<char, int>::iterator it = mp.begin(); it != mp.end();it++) {
        if (it->second > 0) {
            char c = it->first;
            it->second -= 2;
            ps = c + ps + c;
            generatePalindromesDFS(n, ps, mp, result);
            ps.erase(ps.begin());
            ps.pop_back();
            it->second += 2;
        }  
    }
}
vector<string> Solution::generatePalindromes(string s) {
    map<char, int> mp;
    string ps;
    int oddCount = 0;

    vector<string> result;
    for (int i = 0; i < s.length();i++) {
        char c = s[i];
        if (mp.find(c) == mp.end()) {
            oddCount++;
            mp[c] = 1;
        }
        else {
            mp[c]++;
            if (mp[c] % 2 == 1) {
                oddCount++;
            }
            else {
                oddCount--;
            }
        }
    }
    if (oddCount > 1) {
        return result;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second % 2 == 1) {
           ps.push_back(it->first);
           it->second--;
           break;
        }
    }
    generatePalindromesDFS(s.length(), ps, mp, result);
    return result;
}