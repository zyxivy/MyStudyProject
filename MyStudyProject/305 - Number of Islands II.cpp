//A 2d grid map of m rows and n columns is initially filled with water.
//We may perform an addLand operation which turns the water at position(row, col) into a land.
//Given a list of positions to operate, count the number of islands after each addLand operation.
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//You may assume all four edges of the grid are all surrounded by water.
//Example:
//Given m = 3, n = 3, positions = [[0, 0], [0, 1], [1, 2], [2, 1]].
//Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
//0 0 0
//0 0 0
//0 0 0
//Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
//1 0 0
//0 0 0   Number of islands = 1
//0 0 0
//Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
//1 1 0
//0 0 0   Number of islands = 1
//0 0 0
//Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
//1 1 0
//0 0 1   Number of islands = 2
//0 0 0
//Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
//1 1 0
//0 0 1   Number of islands = 3
//0 1 0
//We return the result as an array : [1, 1, 2, 3]
//Challenge :
//    Can you do it in time complexity O(k log mn), where k is the length of the positions ?

#include "Header.h";
//https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
int findRoot(vector<int> & root, int id) {
    while (root[id] != -id) {
        root[id] = root[root[id]];
        id = root[id];
    }
    return id;
}
void unionnumIslands2(vector<int> & root, vector<int>& sz, int root1, int root2, int& cnt ) {
    if (sz[root1] < sz[root2]) {
        root[root1] = root2;
        sz[root2] += sz[root1];
    }
    else {
        root[root2] = root1;
        sz[root1] += sz[root2];
    }
}
vector<int> Solution::numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> roots(m*n, -1);
    vector<int> sz(m*n, 1);
    int cnt = 0;
    vector<int> result;

    vector<vector<int>> dir = { {0,1},{0,-1},{1,0},{-1,0} };
    for (int i = 0; i < positions.size(); i++) {
        int id1 = positions[i].first*n + positions[i].second;
        roots[id1] = id1;
        cnt++;
        for (int j = 0; j < dir.size();j++) {
            int x = positions[i].first*dir[j][0];
            int y = positions[i].second*dir[j][1];
            int id2 = x*n + y;
            if (x > 0 && x < m && y > 0 && y < n && roots[id2] != -1) {
                unionnumIslands2(roots, sz, findRoot(roots, id1), findRoot(roots, id2), cnt);
            }           
        }
        result.push_back(cnt);
    }
    return result;
}
