//Numbers can be regarded as product of its factors.For example,
//8 = 2 x 2 x 2;
//= 2 x 4.
//Write a function that takes an integer n and return all possible combinations of its factors.
//Note:
//Each combination’s factors must be sorted ascending, for example : The factors of 2 and 6 is[2, 6], not [6, 2].
//You may assume that n is always positive.
//Factors should be greater than 1 and less than n.
//Examples :
//    input : 1
//    output :
//    []
//
//input : 37
//    output :
//    []
//
//        input : 12
//            output :
//            [
//                [2, 6],
//                [2, 2, 3],
//                [3, 4]
//            ]
//
//                input : 32
//                    output :
//                    [
//                        [2, 16],
//                        [2, 2, 8],
//                        [2, 2, 2, 4],
//                        [2, 2, 2, 2, 2],
//                        [2, 4, 4],
//                        [4, 8]
//                    ]

#include "Header.h";

void getFactorsHelper(vector<vector<int>>& factors, vector<int>& fac, int n, int start) {
    if (n < 2) {
        factors.push_back(fac);
        return;
    }
    for (int i = start; i <= n; i++) {
        if (n%i == 0) {
            fac.push_back(i);
            getFactorsHelper(factors, fac, n / i, i);
            fac.pop_back();
        }
    }
}

vector<vector<int>> Solution::getFactors(int n) {
    vector<vector<int>> factors;
    if (n <= 3) {
        return factors;
    }
    vector<int> fac;
    getFactorsHelper(factors, fac, n, 2);
    return factors;
}