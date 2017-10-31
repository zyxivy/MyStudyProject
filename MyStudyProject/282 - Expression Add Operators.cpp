//Given a string that contains only digits 0 - 9 and a target value, return all possibilities to add binary operators(not unary) + , -, or *between the digits so they evaluate to the target value.
//Examples:
//"123", 6 ->["1+2+3", "1*2*3"]
//"232", 8 ->["2*3+2", "2+3*2"]
//"105", 5 ->["1*0+5", "10-5"]
//"00", 0 ->["0+0", "0-0", "0*0"]
//"3456237490", 9191 ->[]

#include "Header.h";
void addOperatorsDFS(string num, int target, vector<string> &result, string curr, int pos, long multiPrev, long currResult) {
    if (pos >= num.length()) {
        if (currResult == target) {
            result.push_back(curr);
        }
        return;
    }
    for (int i = pos; i < num.length(); i++) {
        if (i != pos&& num[pos] == '0') {
            break;
        }
        string op = num.substr(pos, i - pos + 1);
        long opValue = stol(op);
        if (pos == 0) {
            addOperatorsDFS(num, target, result, curr + op, i + 1, opValue, opValue);
        }
        else {
            addOperatorsDFS(num, target, result, curr + "+" + op, i + 1, opValue, currResult + opValue);
            addOperatorsDFS(num, target, result, curr + "-" + op, i + 1, -opValue, currResult - opValue);
            addOperatorsDFS(num, target, result, curr + "*" + op, i + 1, multiPrev * opValue, currResult - multiPrev + multiPrev* opValue);
        }
    }
}

vector<string> Solution::addOperators(string num, int target) {
    vector<string> results;
    if (num.length() == 0) {
        return results;
    }
    addOperatorsDFS(num, target, results, "", 0, 0, 0);
    return results;
}