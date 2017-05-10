//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line

#include "Header.h";

int Solution::maxPoints(vector<Point>& points) {
    map<double, int> slopes;

    int maxPoints = 0;

    if (points.size() <= 2) {
        return points.size();
    }

    for (int i = 0; i < points.size(); i++) {
        int verticals = 0;
        int duplicates = 1;
        slopes.clear();
        for (int j = 0; j < points.size(); j++) {
            if (i == j) {
                continue;
            }
            if (points[i].x == points[j].x) {
                if (points[i].y == points[j].y) {
                    duplicates++;
                }
                else {
                    verticals++;
                }
            }
            else {
                double slp = 1000.0*(points[j].y - points[i].y) / (points[j].x - points[i].x);
                if (slopes.find(slp) != slopes.end()) {
                    slopes[slp] = slopes[slp] + 1;
                }
                else {
                    slopes[slp] = 1;
                }
            }
        }
        int curMax = verticals;
        for (map<double, int>::iterator it = slopes.begin(); it != slopes.end();it++) {
            curMax = curMax > it->second ? curMax : it->second;
        }
        curMax += duplicates;
        maxPoints = curMax > maxPoints ? curMax : maxPoints;
    }
    return maxPoints;
}