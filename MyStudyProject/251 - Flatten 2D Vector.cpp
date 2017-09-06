//Implement an iterator to flatten a 2d vector.
//For example,
//Given 2d vector =
//[
//    [1, 2],
//    [3],
//    [4, 5, 6]
//]
//
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be : [1, 2, 3, 4, 5, 6].
//Follow up :
//As an added challenge, try to code it using only iterators in C++ or iterators in Java.


#include "Header.h";
class Vector2D {
public:
    vector<vector<int>> data;
    int x = 0;
    int y = 0;
    int visited = 0;
    int total = 0;
    Vector2D(vector<vector<int>>& vec2d) {
        data = vec2d;
        for (int i = 0; i < vec2d.size(); i++) {
            total += vec2d[i].size();
        }
    }
    int next() {
        while (data[x].empty()) {
            x++;
        }
        int cur = data[x][y];
        while (x < data.size()) {
            if (y == data[x].size() - 1) {
                y = 0;
                x++;
            }
            else {
                y++;
            }
            visited++;
        }
        return cur;
    }
    bool hasNext() {
        return visited < total;
    }
};