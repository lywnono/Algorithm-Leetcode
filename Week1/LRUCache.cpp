class LRUCache {
public:
    int size = 0;
    list<int> cache;
    unordered_map<int, list<int>::iterator> cacheRecord;
    unordered_map<int, int> dataRecord;

    void removeKey(int key) { cache.erase(cacheRecord[key]); }

    void insertKey(int key) {
        cache.push_front(key);
        cacheRecord[key] = cache.begin();
    }

    void envict() {
        dataRecord.erase(cache.back());
        cacheRecord.erase(cache.back());
        cache.pop_back();
    }

    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (dataRecord.find(key) == dataRecord.end())
            return -1;

        removeKey(key);
        insertKey(key);
        return dataRecord[key];
    }

    void put(int key, int value) {
        if (dataRecord.find(key) != dataRecord.end()) {
            dataRecord[key] = value;
            removeKey(key);
            insertKey(key);
        } else {
            if (dataRecord.size() == size) {
                envict();
            }
            dataRecord[key] = value;
            insertKey(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */