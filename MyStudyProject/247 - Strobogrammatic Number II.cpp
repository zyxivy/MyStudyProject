//A strobogrammatic number is a number that looks the same when rotated 180 degrees(looked at upside down).
//Find all strobogrammatic numbers that are of length = n.

#include "Header.h";

vector<string> processString(const vector<string>& vec, int n, int total) {
    vector<string> ret;
    for (string s : vec) {
        if (n != total) {
            ret.push_back("0" + s + "0");
        }
        ret.push_back("1" + s + "1");
        ret.push_back("8" + s + "8");
        ret.push_back("6" + s + "9");
        ret.push_back("9" + s + "6");
    }
    return ret;
}

vector<string> findImp(int n, int total) {
    if (n == 0) {
        return vector<string> { "" };
    }
    if (n == 1) {
        return vector<string> { "0", "1", "6", "8", "9" };
    }
    return processString(findImp(n - 2, total), n, total);
}
vector<string> Solution::findStrobogrammatic(int n) {
    if (n == 0) {
        return vector<string> { "" };
    }
    if (n == 1) {
        return vector<string> { "0", "1", "6", "8", "9" };
    }
    if (n == 2) {
        return vector<string>{ "00", "11", "88", "69", "96" };
    }
    return findImp(n, n);
}