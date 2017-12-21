//You want to build a house on an empty land which reaches all buildings in the shortest amount of distance.You can only move up, down, left and right.You are given a 2D grid of values 0, 1 or 2, where:
//Each 0 marks an empty land which you can pass by freely.
//Each 1 marks a building which you cannot pass through.
//Each 2 marks an obstacle which you cannot pass through.
//For example, given three buildings at(0, 0), (0, 4), (2, 2), and an obstacle at(0, 2) :
//    1 - 0 - 2 - 0 - 1
//    |   |   |   |   |
//    0 - 0 - 0 - 0 - 0
//    |   |   |   |   |
//    0 - 0 - 1 - 0 - 0
//    The point(1, 2) is an ideal empty land to build a house, as the total travel distance of 3 + 3 + 1 = 7 is minimal.So return 7.
//    Note:
//There will be at least one building.If it is not possible to build such house according to the above rules, return -1

#include "Header.h";

//BFS traverse distance of 0s to a 1;

//Traverse the matrix. For 1, use BFS to compute the shortest distance from each '0' to
//1. After we do this for all 1s, we can get the sum of shortest distance
//from every '0' to all reachable 1s.This value is stored
//in 'distance[][]'

//We also count how many building each '0' can be reached. It is stored in reach[][].

//store the total number of buildings in numBuildings. This is to make sure a 0 can reach all 1s.
int Solution::shortestDistance(vector<vector<int>> grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    vector<pair<int, int>> shift{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> distances(m, vector<int>(n, 0));
    vector<vector<int>> reach(m, vector<int>(n, 0));
    int numBuildings = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 1) {
                numBuildings++;
                
                queue<int> q;
                q.push(i*n + j);
                vector<vector<bool>> visited(m, vector<bool>(n, false));                
                int level = 1;

                while (!q.empty()) {
                    for (int qSize = 0; qSize < q.size(); qSize++) {
                        int curM = q.front() / n;
                        int curN = q.front() % n;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nextM = curM + shift[k].first;
                            int nextN = curN + shift[k].second;
                            if (nextM >= 0 && nextM < m && nextN >= 0 && nextN < n && grid[nextM][nextN] == 0 && !visited[nextM][nextN]) {
                                distances[nextM][nextN] += level;
                                reach[nextM][nextN]++;

                                visited[nextM][nextN] = true;
                                q.push(nextM*n + nextN);
                            }
                        }
                    }
                    level++;
                }
            }
        }
    }

    int shortest = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && reach[i][j] == numBuildings) {
                shortest = min(shortest, distances[i][j]);
            }
        }
    }

    return shortest == INT_MAX ? -1 : shortest;
}