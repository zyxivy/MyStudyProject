//Remove the minimum number of invalid parentheses in order to make the input string valid.Return all possible results.
//Note: The input string may contain letters other than the parentheses(and).
//    Examples :
//    "()())()" ->["()()()", "(())()"]
//    "(a)())()" ->["(a)()()", "(a())()"]
//    ")(" ->[""]

#include "Header.h";

bool isValid(string s) {
    int cnt = 0;
    if (s.length() == 0) {
        return false;
    }
    for (auto c : s) {
        if (c != '('&&c != ')') {
            continue;
        }
        else if (c == '(') {
            cnt++;
        }
        else {
            if (cnt == 0) {
                return false;
            }
            cnt--;
        }
    }
    return cnt == 0;
}
vector<string> Solution::removeInvalidParentheses(string s) {
    set<string> visited;
    vector<string> q;

    vector<string> res;

    if (s.length() == 0) {
        return res;
    }

    bool found = false;
    
    visited.insert(s);
    q.push_back(s);
    while (!q.empty()) {

        for (string qs : q) {
            if (isValid(qs)) {
                found = true;
                res.push_back(qs);
            }
        }
        if (found)
            break;

        string str = q.back();
        q.pop_back();
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != '('&&str[i] != ')') {
                continue;
            }
            string t = str.substr(0, i) + str.substr(i + 1, str.length() - i - 1);
            if (visited.find(t) == visited.end()) {
                visited.insert(t);
                q.push_back(t);
            }
        }
    }
    if (res.empty()) {
        res.push_back("");
    }
    return res;

}