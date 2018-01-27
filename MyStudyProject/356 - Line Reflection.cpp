//Given n points on a 2D plane, find if there is such a line parallel to y - axis that reflect the given set of points.
//Example 1:
//Given points = [[1, 1], [-1, 1]], return true.
//Example 2 :
//    Given points = [[1, 1], [-1, -1]], return false.
//    Follow up :
//Could you do better than O(n2) ?
//Hint :
//    Find the smallest and largest x - value for all points.
//    If there is a line then it should be at y = (minX + maxX) / 2.
//    For each point, make sure that it has a reflected point in the opposite side.

#include "Header.h";
bool isRefelectedComp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}
bool Solution::isReflected(vector<pair<int, int>>& points) {
    int mn = INT_MAX;
    int mx = INT_MIN;
    unordered_map<int, unordered_set<int>> mp;
    for (auto p : points)
    {
        mn = min(mn, p.first);
        mx = max(mx, p.first);
        mp[p.first].insert(p.second);
    }

    int sum = mn + mx;
    for (auto p : points) {
        int t = sum - p.first;
        if (mp.find(t) == mp.end() || mp[t].find(p.second) == mp[t].end()) {
            return false;
        }
    }
    return true;
}