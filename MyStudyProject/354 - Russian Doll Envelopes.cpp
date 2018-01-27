//You have a number of envelopes with widths and heights given as a pair of integers(w, h).
//One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//What is the maximum number of envelopes can you Russian doll ? (put one inside other)
//Example :
//    Given envelopes = [[5, 4], [6, 4], [6, 7], [2, 3]], the maximum number of envelopes you can Russian doll is 3 ([2, 3] = >[5, 4] = >[6, 7]).

#include "Header.h";
int Solution::maxEnvelopes(vector<pair<int, int>> es) {
    sort(es.begin(), es.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second); });
    vector<int> dp;
    for (auto e : es)
    {
        auto iter = lower_bound(dp.begin(), dp.end(), e.second);
        if (iter == dp.end())
            dp.push_back(e.second);
        else if (e.second < *iter)
            *iter = e.second;
    }
    return dp.size();
}