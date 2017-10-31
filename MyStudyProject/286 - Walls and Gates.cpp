//You are given a m x n 2D grid initialized with these three possible values.
//- 1 – A wall or an obstacle.
//0 – A gate.
//INF – Infinity means an empty room.
//We use the value 231 – 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
//Fill each empty room with the distance to its nearest gate.If it is impossible to reach a gate, it should be filled with INF.
//For example, given the 2D grid :
//INF - 1 0 INF
//INF INF INF - 1
//INF - 1 INF - 1
//0 - 1 INF INF
//After running your function, the 2D grid should be :
//3 - 1 0 1
//2 2 1 - 1
//1 - 1 2 - 1
//0 - 1 3 4

#include "Header.h";
void wallsAndGatesDFS(vector<vector<int>>& rooms, int x, int y, int idx) {
    if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms.size() || rooms[x][y] < idx) {
        return;
    }
    rooms[x][y] = idx;
    wallsAndGatesDFS(rooms, x + 1, y, idx + 1);
    wallsAndGatesDFS(rooms, x - 1, y, idx + 1);
    wallsAndGatesDFS(rooms, x, y + 1, idx + 1);
    wallsAndGatesDFS(rooms, x, y - 1, idx + 1);
}
void Solution::wallsAndGates(vector<vector<int>> rooms) {
    int Tx = rooms.size();
    if (Tx == 0) {
        return;
    }
    int Ty = rooms[0].size();
    for (int x = 0; x < Tx; x++) {
        for (int y = 0; y < Ty; y++) {
            if (rooms[x][y] == 0) {
                wallsAndGatesDFS(rooms, x, y, 0);
            }
        }
    }

    Tx = rooms.size();
}