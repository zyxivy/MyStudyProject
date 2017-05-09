//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Return :
//
//    [
//        ["ate", "eat", "tea"],
//        ["nat", "tan"],
//    ["bat"]
//    ]

#include "Header.h";
#include <map>;

int partition(string& str, int l, int r) {
    int pivot = str[r];
    int wall = l;
    while (l < r) {
        if (str[l] < pivot) {
            char tmp = str[l];
            str[l] = str[wall];
            str[wall] = tmp;
            wall++;
        }
        l++;
    }
    char tmp = str[r];
    str[r] = str[wall];
    str[wall] = tmp;
    return wall;
}

void quicksort(string& str, int l, int r) {
    if (l < r) {
        int p = partition(str, l, r);
        quicksort(str, l, p - 1);
        quicksort(str, p + 1, r);
    }
}

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> stringmap;
    for (int i = 0;i < strs.size();i++) {
        string str = strs[i];
        quicksort(str, 0, str.length()-1);
        stringmap[str].push_back(strs[i]);
    }

    vector<vector<string>> ret;
    map<string, vector<string>>::iterator it = stringmap.begin();
    while(it!=stringmap.end()) {
        ret.push_back(it->second);
        it++;
    }
    return ret;
}