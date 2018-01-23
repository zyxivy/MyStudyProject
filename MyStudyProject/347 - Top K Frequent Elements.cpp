//Given a non - empty array of integers, return the k most frequent elements.
//For example,
//Given[1, 1, 1, 2, 2, 3] and k = 2, return[1, 2].
//Note:
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
#include "Header.h";
vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
    map<int, int> mp;
    for (int n : nums) {
        mp[n]++;
    }

    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    int pqSize = mp.size() - k;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        pq.push(make_pair(it->second, it->first));
        if (pq.size() > pqSize) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
    return ans;
}