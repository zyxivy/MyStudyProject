//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//    [1],
//    [1, 1],
//    [1, 2, 1],
//    [1, 3, 3, 1],
//    [1, 4, 6, 4, 1]
//]
#include "Header.h";
vector<vector<int>> Solution::generatePascalTriangle(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0) {
        return result;
    }
    vector<int> rowPrev = { 1 };
    result.push_back(rowPrev);
    for (int i = 1;i < numRows;i++) {
        vector<int> rowNew;
        rowNew.push_back(1);
        for (int j = 0;j < rowPrev.size() - 1;j++) {
            rowNew.push_back(rowPrev[j] + rowPrev[j + 1]);
        }
        rowNew.push_back(1);
        result.push_back(rowNew);
        rowPrev = rowNew;
    }
    return result;
}