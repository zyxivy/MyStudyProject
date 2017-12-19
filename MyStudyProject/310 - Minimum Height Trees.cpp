//For a undirected graph with tree characteristics, we can choose any node as the root.The result graph is then a rooted tree.Among all possible rooted trees, those with minimum height are called minimum height trees(MHTs).Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//Format
//The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges(each edge is a pair of labels).
//You can assume that no duplicate edges will appear in edges.Since all edges are undirected, [0, 1] is the same as[1, 0] and thus will not appear together in edges.
//Example 1:
//Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
//0
//|
//1
/// \
//2   3
//return[1]
//Example 2:
//Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
//0  1  2
//\ | /
//3
//|
//4
//|
//5
//return[3, 4]
//Note:
//(1) According to the definition of tree on Wikipedia : “a tree is an undirected graph in which any two vertices are connected by exactly one path.In other words, any connected graph without simple cycles is a tree.”
//(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

#include "Header.h";

//"keep deleting leaves layer-by-layer, until there're only 2 or 1 nodes left, the remaining nodes are the roots."
vector<int> Solution::findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<unordered_set<int>> adj(n);

    for (auto p : edges) {
        adj[p.first].insert(p.second);
        adj[p.second].insert(p.first);
    }

    vector<int> leaves;

    if (n < 2) {
        leaves.push_back(0);
        return leaves;
    }
    if (n == 2) {
        leaves.push_back(0);
        leaves.push_back(1);
        return leaves;
    }
    for (int i = 0; i < n;i++) {
        if (adj[i].size() == 1) {
            leaves.push_back(i);
        }
    }

    while (n > 2) {
        vector<int> tmpLeaves;
        for (int node:leaves) {
            for (int neighbor : adj[node]) {
                adj[neighbor].erase(node);
                if (adj[neighbor].size() == 1) {
                    tmpLeaves.push_back(neighbor);
                }
            }
        }
        n -= leaves.size();
        leaves=tmpLeaves;

    }

    return leaves;
}