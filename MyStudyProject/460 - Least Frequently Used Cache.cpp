//
//Design and implement a data structure for Least Frequently Used(LFU) cache.It should support the following operations : get and put.
//get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present.When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item.For the purpose of this problem, when there is a tie(i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
//Follow up :
//Could you do both operations in O(1) time complexity ?
//Example :
//    LFUCache cache = new LFUCache(2 /* capacity */);
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.get(3);       // returns 3.
//cache.put(4, 4);    // evicts key 1.
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4

#include "Header.h";

//min will always reset to 1 when adding a new item.
//And also, min can never jump forward more than 1 since updating an item only increments it’s count by 1
//https://leetcode.com/problems/lfu-cache/discuss/94521/JAVA-O(1)-very-easy-solution-using-3-HashMaps-and-LinkedHashSet

class LFUCache {
    unordered_map<int, int> key_val;
    unordered_map<int, int> key_freq;
    unordered_map<int, list<int>> freq_keys;
    unordered_map<int, list<int>::iterator> key_iter;
    int minFreq = -1;
    int cap;

public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (key_val.find(key) == key_val.end()) {//cache miss
            return -1;
        }

        int freq = key_freq[key];
        key_freq[key] = freq + 1; //update frequency

        freq_keys[freq].erase(key_iter[key]);
        //if key is already LFU with frequency "count", and is the only item with frequency "count", increase min frequency
        if (freq == minFreq && freq_keys[freq].empty()) {
            minFreq++;
        }

        //frequency plus 1, check if there is no count+1, insert a new set.
        if (freq_keys.find(freq + 1) == freq_keys.end()) {
            list<int> newkeys;
            freq_keys[freq + 1] = newkeys;
        }
        freq_keys[freq + 1].push_front(key);
        key_iter[key] = freq_keys[freq + 1].begin();

        return key_val[key];
    }

    void put(int key, int value) {
        if (cap <= 0) {
            return;
        }

        //if key already in cache, update value and touch frequency
        if (key_val.find(key) != key_val.end()) {
            key_val[key] = value;
            get(key);
            return;
        }

        //if cache is full, pop the least frequently used one
        if (key_val.size() >= cap) {
            int keyToRemove = freq_keys[minFreq].back();
            key_val.erase(keyToRemove);
            key_freq.erase(keyToRemove);
            freq_keys[minFreq].pop_back();
            if (freq_keys[minFreq].empty()) {
                freq_keys.erase(minFreq);
            }
            key_iter.erase(keyToRemove);
        }

        // add new key to cache
        minFreq = 1;
        key_val[key] = value;
        key_freq[key] = 1;
        if (freq_keys.find(minFreq) == freq_keys.end()) {
            list<int> newkeys;
            freq_keys[minFreq] = newkeys;
        }
        freq_keys[minFreq].push_front(key);
        key_iter[key] = freq_keys[minFreq].begin();
    }
};
