//Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once.You must make sure your result is the smallest in lexicographical order among all possible results.
//Example:
//Given "bcabc"
//Return "abc"
//Given "cbacdcbc"
//Return "acdb"

#include "Header.h";    

//https://discuss.leetcode.com/topic/43469/java-o-n-solution-using-stack-with-detail-explanation/2
string Solution::removeDuplicateLetters(string s) {
    stack<char> stack;
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }
    vector<bool> visited(26, false);
    for (char c : s) {
        count[c - 'a']--;
        if (visited[c - 'a']) {
            continue;
        }
        while (!stack.empty() && stack.top() > c && count[stack.top() - 'a'] > 0) {
            visited[stack.top() - 'a'] = false;
            stack.pop();
        }
        stack.push(c);
        visited[c - 'a'] = true;
    }
    string sb;
    while (!stack.empty()) {
        sb.insert(sb.begin(), stack.top());
        stack.pop();
    }
    return sb;
}