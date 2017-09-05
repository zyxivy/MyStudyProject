//Discuss
//Pick One
//
//
//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators.The valid operators are + , -and *.
//
//Example 1
//Input: "2-1-1".
//    ((2 - 1) - 1) = 0
//    (2 - (1 - 1)) = 2
//    Output : [0, 2]
//
//    Example 2
//    Input : "2*3-4*5"
//    (2 * (3 - (4 * 5))) = -34
//    ((2 * 3) - (4 * 5)) = -14
//    ((2 * (3 - 4)) * 5) = -10
//    (2 * ((3 - 4) * 5)) = -10
//    (((2 * 3) - 4) * 5) = 10
//    Output : [-34, -14, -10, -10, 10]

#include "Header.h";
//http://yucoding.blogspot.com/2016/09/leetcode-question-different-ways-to-add.html
vector<int> diffWaysToComputeSearch(string input) {
    vector<int> res;
    vector<int> left;
    vector<int> right;

    if (input.find('+') == -1 && input.find('-') == -1 && input.find('*') == -1) {
        int tmp;
        tmp = stoi(input);
        res.push_back(tmp);
    }
    else {
        for (int i = 1; i<input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                left = diffWaysToComputeSearch(input.substr(0, i));
                right = diffWaysToComputeSearch(input.substr(i + 1));
                for (int j = 0; j<left.size(); j++) {
                    for (int k = 0; k<right.size(); k++) {
                        int val = 0;
                        if (input[i] == '+') { val = left[j] + right[k]; }
                        if (input[i] == '-') { val = left[j] - right[k]; }
                        if (input[i] == '*') { val = left[j] * right[k]; }
                        res.push_back(val);
                    }
                }
            }
        }
    }
    return res;
}
vector<int> Solution::diffWaysToCompute(string input){
    vector<int> result;
    if (input.size() == 0) { return result; }
    return diffWaysToComputeSearch(input);
}