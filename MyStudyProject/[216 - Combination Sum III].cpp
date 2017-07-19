//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Example 1:
//Input: k = 3, n = 7
//    Output :
//
//    [[1, 2, 4]]
//
//
//       Example 2 :
//           Input : k = 3, n = 9
//           Output :
//
//           [[1, 2, 6], [1, 3, 5], [2, 3, 4]]

#include "Header.h";
int getSum(vector<int> instance) {
    int sum = 0;
    for (int i = 0; i < instance.size(); i++) {
        sum += instance[i];
    }
    return sum;
}

void dfs(vector<int> instance, vector<vector<int> >& res, int start, int n, int k) {

    if (instance.size() == k) {
        int sum = getSum(instance);
        if (sum > n) {
            return;
        }
        else if (sum == n) {
            res.push_back(instance);
            return;
        }
    }

    for (int i = start; i <= 9; i++) {
        instance.push_back(i);
        dfs(instance, res, i + 1, n, k);
        instance.pop_back();
    }
}
vector<vector<int>> Solution::combinationSum3(int k, int n) {
    if (k < 1 || k > 9) {
        return vector<vector<int> >();
    }

    if (n < 1 || n > 45) {
        return vector<vector<int> >();
    }

    vector<vector<int> > res;
    vector<int> instance;

    dfs(instance, res, 1, n, k);

    return res;
}