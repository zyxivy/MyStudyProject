//Design and implement a data structure for Least Recently Used(LRU) cache.It should support the following operations : get and put.
//get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//Follow up :
//Could you do both operations in O(1) time complexity ?
//Example :
//    LRUCache cache = new LRUCache(2 /* capacity */);
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4

#include "Header.h";
class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
private:
    int m_capacity;
    struct CacheEntry {
        int key;
        int val;
        CacheEntry(int x, int y) : key(x), val(y) {}
    };
    vector<CacheEntry> queue;
    map<int, vector<CacheEntry>::iterator> mp;
};
//http://fisherlei.blogspot.com/2013/11/leetcode-lru-cache-solution.html
LRUCache::LRUCache(int capacity) {
    m_capacity = capacity;
}

int LRUCache::get(int key) {
    if (mp.find(key)== mp.end()) {// cache miss
        return -1;
    }
    // cache hit
    CacheEntry item = *mp[key];

    queue.erase(mp[key]);
    queue.insert(queue.begin(), item);
    mp[key] = queue.begin();
    return queue.begin()->val;
}

void LRUCache::put(int key, int value) {
        
    if (mp.find(key) != mp.end()) { // cache hit
        CacheEntry item = *mp[key]; 
        queue.erase(mp[key]);
        queue.insert(queue.begin(), item);

        mp[key] = queue.begin();
        mp[key]->val = value;
    }
    else {// cache miss
        CacheEntry item(key, value);
        if (queue.size() == m_capacity) {
            mp.erase(queue.end()->key);
            queue.pop_back();
        }
        queue.insert(queue.begin(), item);
        mp[key] = queue.begin();
    }
}


