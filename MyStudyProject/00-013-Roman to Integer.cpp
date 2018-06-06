//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

//Symbol	I	V	X	L	C	D	M
//Value	    1	5	10	50	100	500	1000

#include "Header.h";

int Solution::romanToInt(string s) {

    int len=s.length();
    int ans = 0;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == 'I') {
            if (i + 1 < len && s[i+1]!='I') {
                if (s[i + 1] == 'V') {
                    ans += 4;
                    i++;
                }
                else if (s[i + 1] == 'X') {
                    ans += 9;
                    i++;
                }
                else {
                    ans += 1;
                }
            }
            else {
                ans += 1;
            }
        }
        else if (s[i] == 'X') {
            if (i + 1 < len && s[i + 1] != 'X') {
                if (s[i + 1] == 'L') {
                    ans += 40;
                    i++;
                }
                else if (s[i + 1] == 'C') {
                    ans += 90;
                    i++;
                }
                else {
                    ans += 10;
                }
            }
            else {
                ans += 10;
            }
        }
        else if (s[i] == 'C') {
            if (i + 1 < len && s[i + 1] != 'C') {
                if (s[i + 1] == 'D') {
                    ans += 400;
                    i++;
                }
                else if (s[i + 1] == 'M') {
                    ans += 900;
                    i++;
                }
                else {
                    ans += 100;
                }
            }
            else {
                ans += 100;
            }
        }
        else if (s[i] == 'V') {
            ans += 5;
        }
        else if (s[i] == 'L') {
            ans += 50;
        }
        else if (s[i] == 'D') {
            ans += 500;
        }
        else if (s[i] == 'M') {
            ans += 1000;
        }
    }
    return ans;
}