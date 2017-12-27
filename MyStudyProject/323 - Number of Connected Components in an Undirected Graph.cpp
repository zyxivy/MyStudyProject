//Given n nodes labeled from 0 to n - 1 and a list of undirected edges(each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
//Example 1:
//0          3
//|          |
//1 -- - 2    4
//Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
//Example 2 :
//    0           4
//    |           |
//    1 -- - 2 -- - 3
//    Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
//    Note :
//    You can assume that no duplicate edges will appear in edges.Since all edges are undirected, [0, 1] is the same as[1, 0] and thus will not appear together in edges.

#include "Header.h";

int findRoot(vector<int>& root, int id) {
    while (root[id] != id) {
        root[id] = root[root[id]];
        id = root[id];
    }
    return id;
}
int Solution::countComponents(int n, vector<vector<int>> edges) {
    vector<int> root(n, 0);
    for (int i = 0; i < n; i++) {
        root[i] = i;
    }

    for (auto e:edges) {
        int r1 = findRoot(root, e[0]);
        int r2 = findRoot(root, e[1]);
        if (r1 != r2) {
            root[r1] = r2;
            n--;
        }
    }
    return n;
}