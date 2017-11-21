//Remove the minimum number of invalid parentheses in order to make the input string valid.Return all possible results.
//Note: The input string may contain letters other than the parentheses(and).
//    Examples :
//    "()())()" ->["()()()", "(())()"]
//    "(a)())()" ->["(a)()()", "(a())()"]
//    ")(" ->[""]

#include "Header.h";

bool isValid(string s) {
    int cnt = 0;
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
    queue<string> q;

    vector<string> res;

    if (s.length() == 0) {
        return res;
    }

    bool found = false;
    
    visited.insert(s);
    q.push(s);
    while (!q.empty()) {
        string str = q.front();
        q.pop();

        if (isValid(str)) {
            res.push_back(str);
            found = true;
        }
        if (found)
            break;

 
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != '('&&str[i] != ')') {
                continue;
            }
            string t = str.substr(0, i) + str.substr(i + 1, str.length() - i - 1);
            if (visited.find(t) == visited.end()) {
                visited.insert(t);
                q.push(t);
            }
        }
    }
    return res;

}