//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.
//Input:Digit string "23"
//    Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#include "Header.h";



void buildLetter(string digits, int begin, string curString, string table[], vector<string> &records) {
    if (curString.length() == digits.length())
    {
        records.push_back(curString);
        return;
    }
    for (int i = 0;i < table[digits[begin] - '0'].length();i++) {
        curString += table[digits[begin] - '0'][i];
        buildLetter(digits, begin + 1, curString, table, records);
        curString = curString.substr(0, curString.length() - 1);
    }
}
vector<string> Solution::letterCombinations(string digits) {
    
    string table[] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> records;
    string curString;
    if (digits.length() == 0) {
        return records;
    }
    buildLetter(digits, 0, curString, table, records);
    return records;
}