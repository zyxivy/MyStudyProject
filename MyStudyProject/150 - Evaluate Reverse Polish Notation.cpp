//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//Some examples :
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include "Header.h";

bool isOperator(string s) {
    if (s == "+" || s == "-" || s == "*" || s == "/") {
        return true;
    }
    return false;
}

int Solution::evalRPN(vector<string>& tokens) {
    vector<int> stack;
    if (tokens.size() == 0) {
        return 0;
    }
    for (int i = 0; i < tokens.size(); i++) {
        if (!isOperator(tokens[i])) {
            stack.push_back(stoi(tokens[i]));
        }
        else {
            int op1 = stack.back();
            stack.pop_back();
            int op2 = stack.back();
            stack.pop_back();

            int result = 0;
            if (tokens[i] == "+") {
                result = op1 + op2;
            }
            else if(tokens[i] == "-") {
                result = op2 - op1;
            }
            else if(tokens[i] == "*") {
                result = op1 * op2;
            }
            else if(tokens[i] == "/") {
                result = op2 / op1;
            }
            stack.push_back(result);
        }
    }

    return stack[0];
}