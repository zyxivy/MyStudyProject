//Given n nodes labeled from 0 to n - 1 and a list of undirected edges(each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//Notice
//You can assume that no duplicate edges will appear in edges.Since all edges are undirected, [0, 1] is the same as[1, 0] and thus will not appear together in edges.
//Example
//Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
//Tags
//Depth First Search Facebook Zenefits Union Find Breadth First Search Google
//Related Problems
//Medium Find the Connected Component in the Undirected Graph


//Union-Find
//https://aaronice.gitbooks.io/lintcode/content/union_find/graph_valid_tree.html
#include "Header.h";

class UnionFind {
    // Implemented with array instead of HashMap for simplicity
    vector<int> parent;
public:
    // Constructor
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        return compressed_find(x);
    }

    int compressed_find(int x) {
        int x_parent = parent[x];
        while (x_parent != parent[x_parent]) {
            x_parent = parent[x_parent];
        }

        int temp = -1;
        int t_parent = parent[x];
        while (t_parent != parent[t_parent]) {
            temp = parent[t_parent];
            parent[t_parent] = x_parent;
            t_parent = temp;
        }
        return x_parent;
    }
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent != y_parent) {
            parent[x_parent] = y_parent;
        }
    }
};
/**
* @param n an integer
* @param edges a list of undirected edges
* @return true if it's a valid tree, or false
*/
bool validTreeUnionFind(int n, vector<pair<int, int>> edges) {
    // Validation of |V| - 1 = |E|
    if (n - 1 != edges.size() || n == 0) {
        return false;
    }
    UnionFind uf(n);
    for (int i = 0; i < edges.size(); i++) {
        if (uf.find(edges[i].first) == uf.find(edges[i].second)) {
            return false;
        }
        uf.Union(edges[i].first, edges[i].second);
    }
    return true;
}




//DFS
bool validTreeDFSHelper(int cur, int parent, vector<vector<int>> mp, vector<bool> &visited) {
    if (visited[cur])
        return false;

    visited[cur] = true;

    for (int i : mp[cur]) {
        if (i != parent && !validTreeDFSHelper(i, cur, mp, visited)) {
            return false;
        }
    }

    return true;
}

bool validTreeDFS(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> mp;
    int len = edges.size();

    for (int i = 0; i < n; i++) {
        vector<int> l;
        mp.push_back(l);
    }

    for (int i = 0; i < len; i++) {
        mp[edges[i].first].push_back(edges[i].second);
        mp[edges[i].second].push_back(edges[i].first);
    }

    vector<bool>visited(n, 0);

    if (!validTreeDFSHelper(0, -1, mp, visited))
    {
        return false;
    }
        
    for (int i = 0; i < n;i++) {
        if (visited[i] == false) {
            return false;
        }
    }

    return true;
}




//BFS
bool Solution::validTree(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> mp;
    int len = edges.size();

    for (int i = 0; i < n; i++) {
        vector<int> l;
        mp.push_back(l);
    }

    for (int i = 0; i < len; i++) {
        mp[edges[i].first].push_back(edges[i].second);
        mp[edges[i].second].push_back(edges[i].first);
    }

    vector<bool>visited(n, 0);

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int top = q.back();
        q.pop();

        if (visited[top])
            return false;

        visited[top] = true;

        for (int i : mp[top]) {
            if (!visited[i])
                q.push(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            return false;
        }
    }

    return true;
}