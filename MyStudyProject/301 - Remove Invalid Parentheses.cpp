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
void removeInvalidParenthesesdfs(string s, int beg, int num1, int num2, vector<string> &ret) {
    if (num1 == 0 && num2 == 0) {
        if (isValid(s))
            ret.push_back(s);
    }
    else {
        for (int i = beg; i < s.size(); ++i) {
            string tmp = s;
            if (num2 == 0 && num1 > 0 && tmp[i] == '(') {
                if (i == beg || tmp[i] != tmp[i - 1]) {
                    tmp.erase(i, 1);
                    removeInvalidParenthesesdfs(tmp, i, num1 - 1, num2, ret);
                }
            }
            if (num2 > 0 && tmp[i] == ')') {
                if (i == beg || tmp[i] != tmp[i - 1]) {
                    tmp.erase(i, 1);
                    removeInvalidParenthesesdfs(tmp, i, num1, num2 - 1, ret);
                }
            }
        }
    }
}

vector<string> Solution::removeInvalidParentheses(string s) {
    int num1 = 0, num2 = 0;
    for (char &c : s) {
        num1 += c == '(';
        if (num1 == 0) {
            num2 += c == ')';
        }
        else {
            num1 -= c == ')';
        }
    }
    vector<string> ret;
    removeInvalidParenthesesdfs(s, 0, num1, num2, ret);
    return ret;
}

//vector<string> Solution::removeInvalidParentheses(string s) {
    //set<string> visited;
    //queue<string> q;

    //vector<string> res;

    //if (s.length() == 0) {
    //    return res;
    //}

    //bool found = false;
    //
    //visited.insert(s);
    //q.push(s);
    //while (!q.empty()) {
    //    string str = q.front();
    //    q.pop();

    //    if (isValid(str)) {
    //        res.push_back(str);
    //        found = true;
    //    }
    //    if (found)
    //        break;

 
    //    for (int i = 0; i < str.length(); i++) {
    //        if (str[i] != '('&&str[i] != ')') {
    //            continue;
    //        }
    //        string t = str.substr(0, i) + str.substr(i + 1, str.length() - i - 1);
    //        if (visited.find(t) == visited.end()) {
    //            visited.insert(t);
    //            q.push(t);
    //        }
    //    }
    //}
    //return res;

//}