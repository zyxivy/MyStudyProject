//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example :
//Given "25525511135",
//
//return["255.255.11.135", "255.255.111.35"]. (Order does not matter)
#include "Header.h";

bool isValid(string s, int start, int end) {
    if (start > s.length()-1 || end > s.length()-1 || end < start || end - start > 2) {
        return false;
    }
    if (end - start == 2) {
        if (s[start] == '0') {
            return false;
        }
        if (s[start] > '2' || (s[start] == '2' && s[start + 1] > '5') || (s[start] == '2' && s[start + 1] == '5' && s[start + 2] > '5')) {
            return false;
        }
    }
    else if (end - start == 1) {
        if (s[start] == '0') {
            return false;
        }
    }
    else if (end == start) {
        if (s[start] < '0' && s[start] < '9') {
            return false;
        }
    }
    return true;
}

void recursive(string s, int start, int k, vector<string>& ret, string ip) {
    if (k == 4) {
        if (isValid(s, start, s.length()-1)) {
            ip += "." + s.substr(start);
            ret.push_back(ip);
        }
        return;
    }
    for (int i = 1;i <= 3;i++) {
        if (isValid(s, start, start + i-1)) {
            string tmp = ip == "" ? s.substr(start, i) : ip + "." + s.substr(start, i);
            recursive(s, start + i, k + 1, ret, tmp);
        }
        else {
            break;
        }
    }
}

vector<string> Solution::restoreIpAddresses(string s) {
    vector<string> ret;
    string ip = "";
    if (s.length() < 4 || s.length() > 12) {
        return ret;
    }
    recursive(s, 0, 1, ret, ip);
    return ret;
}