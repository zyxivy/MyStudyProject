//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//For example,
//Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".


//http://www.meetqun.net/thread-3328-1-1.html
#include "Header.h"
string Solution::fractionToDecimal(int numerator, int denominator) {
    string out;
    long long Numerator = numerator, Denominator = denominator;
    if (Denominator < 0) {
        Denominator = -Denominator;
        Numerator = -Numerator;

    }
    if (Numerator < 0) {
        Numerator = -Numerator;
        out += "-";
    }
    out += to_string(Numerator / Denominator);
    long long remainder = Numerator % Denominator;
    if (remainder == 0) {
        return out;
    }
    out += ".";
    vector<int> save;
    map<int, int> have;
    for (int i = 0; remainder && (have.find(remainder) == have.end()); ++i) {
        have[remainder] = i;
        remainder *= 10;
        save.push_back(remainder / Denominator);
        remainder %= Denominator;
    }
    if (remainder) {
        for (int j = 0; j < have[remainder]; ++j) {
            out += to_string(save[j]);
        }
        out += "(";
        for (int j = have[remainder]; j < save.size(); ++j) {
            out += to_string(save[j]);
        }
        out += ")";
    }
    else {
        for (int j = 0; j < save.size(); ++j) {
            out += to_string(save[j]);

        }
    }
    return out;
}