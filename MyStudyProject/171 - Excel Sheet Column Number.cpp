//Related to question Excel Sheet Column Title
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//For example :
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28

#include "Header.h";

int Solution::titleToNumber(string s) {
    if (s.empty()) {
        return 0;
    }
    int result = 0;
    for (int i = 0; i < s.length(); ) {
        result += s[i] - 'A' + 1;
        i++;
        if (i != s.length()) {
            result = result * 26;
        }
    }
    return result;
}