//Design and implement a data structure for Least Recently Used(LRU) cache.It should support the following operations : get and put.
//
//get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
//Follow up :
//Could you do both operations in O(1) time complexity ?
//
//Example :
//
//	LRUCache cache = new LRUCache(2 /* capacity */);
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

#include "header.h";

class dListNode {
public:
	int key;
	int val;
	dListNode* prev;
	dListNode* next;

	dListNode(int key, int value) {
		this->key = key;
		this->val = value;
	}
};

class LRUCache {
private:
	int capacity = 0;
	dListNode * dummyHead = nullptr;
	dListNode * dummyTail = nullptr;
	unordered_map<int, dListNode*> mp;


	void addTodummyHead(dListNode* node) {
		node->next = dummyHead->next;
		dummyHead->next->prev = node;
		dummyHead->next = node;
		node->prev = dummyHead;
	}

	void moveTodummyHead(dListNode* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
		addTodummyHead(node);
	}

	void removeTail() {
		dListNode* tmp = dummyTail->prev->prev;
		tmp->next = dummyTail;
		dummyTail->prev = tmp;
	}

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		dummyHead = new dListNode(-1, -1);
		dummyTail = new dListNode(-1, -1);
		dummyHead->next = dummyTail;
		dummyTail->prev = dummyHead;
	}

	int get(int key) {
		if (mp.count(key)) {
			dListNode* node = mp[key];
			int ret = node->val;
			moveTodummyHead(node);

			return ret;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (mp.count(key)) {
			dListNode* node = mp[key];
			moveTodummyHead(node);

			//update content
			node->val = value;
			mp[key] = node;
		}
		else {
			dListNode* node = new dListNode(key, value);
			if (capacity == mp.size()) {
				mp.erase(dummyTail->prev->key);
				removeTail();
			}
			mp[key] = node;
			addTodummyHead(node);
		}
	}
};
//
//int main() {
//	LRUCache cache(2);
//	cache.put(1, 1);
//	cache.put(2, 2);
//	cache.get(1);
//
//	cache.put(3, 3);
//	cache.get(2);
//
//	cache.put(4, 4);
//	cache.get(1);
//	cache.get(3);
//
//}