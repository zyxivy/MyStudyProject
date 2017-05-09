//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.


//Symbol	I	V	X	L	C	D	M
//Value	    1	5	10	50	100	500	1000

#include "Header.h"
string Solution::intToRoman(int x) {
    string ret;
    if (x >= 1000) {
        while(x>=1000) {
            x -= 1000;
            ret += "M";
        }
    }
    int scale = 100;
    string symbols[] = {"I", "V", "X", "L", "C", "D", "M"};

    for (int i = 4;i>=0;i-=2) {
        int digit = x / scale;

        if (digit >= 9) {
            ret += symbols[i];
            ret += symbols[i + 2];
        }
        else if (digit >= 5) {
            ret += symbols[i + 1];
            while (digit > 5) {
                ret += symbols[i];
                digit--;
            }
        }
        else if (digit>=4) {
            ret += symbols[i];
            ret += symbols[i + 1];
        }
        else if (digit >= 1) {
            while (digit >= 1) {
                ret += symbols[i];
                digit--;
            }
        }
        x %= scale;
        scale /= 10;
        
    }
    return ret;

}