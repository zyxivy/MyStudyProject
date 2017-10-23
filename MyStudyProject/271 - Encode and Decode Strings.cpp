//Design an algorithm to encode a list of strings to a string.The encoded string is then sent over the network and is decoded back to the original list of strings.
//Machine 1 (sender)has the function :
//string encode(vector<string> strs) {
//    // ... your code
//    return encoded_string;
//}
//Machine 2 (receiver)has the function :
//vector<string> decode(string s) {
//    //... your code
//    return strs;
//}
//
//So Machine 1 does:
//string encoded_string = encode(strs);
//
//and Machine 2 does:
//vector<string> strs2 = decode(encoded_string);
//
//strs2 in Machine 2 should be the same as strs in Machine 1.
//Implement the encode and decode methods.
//Note:
//The string may contain any possible characters out of 256 valid ascii characters.Your algorithm should be generalized enough to work on any possible characters.
//Do not use class member / global / static variables to store states.Your encode and decode algorithms should be stateless.
//Do not rely on any library method such as eval or serialize methods.You should implement your own encode / decode algorithm.

#include "Header.h";

//http://www.bo-song.com/leetcode-encode-and-decode-strings/
string Solution::encode(vector<string> strs) {
    string str;
    if (strs.size() == 0) {
        return str;
    }

    for (string s : strs) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '\\' || s[i] == ',') {
                str.push_back('\\');
            }
            str.push_back(s[i]);
        }
        str.push_back(',');
    }
    return str;
}

vector<string> Solution::decode(string s) {
    vector<string> strings;    
    string str;
    bool isEscape = false;

    for (int i = 0; i < s.length(); i++) {
        if (isEscape) {
            isEscape = false;
            str.push_back(s[i]);
        }
        else {
            if (s[i] == '\\') {
                isEscape = true;
            }
            else if (s[i] == ',') {
                strings.push_back(str);
                str.clear();
            }
            else {
                str.push_back(s[i]);
            }
        }
    }
    return strings;
}