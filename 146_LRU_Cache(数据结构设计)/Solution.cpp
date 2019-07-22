#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache {
private:
    const int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> location;
public:
    LRUCache(const int& capacity) :capacity(capacity) {
    }

    int get(const int& key) {
        auto iter(location.find(key));
        if (iter != location.end()) {//数据存在
            pair<int, int> p(*(iter->second));
            cacheList.erase(iter->second);
            cacheList.push_front(p);
            location[key] = cacheList.begin();
            return p.second;
        }
        else {
            return -1;
        }

    }

    void put(const int& key, const int& value) {
        auto iter(location.find(key));
        if (iter != location.end()) {//更新原有数据并且刷新位置
            cacheList.erase(iter->second);
            cacheList.push_front(pair<int, int>(key, value));
            location[key] = cacheList.begin();
        }
        else {
            if (cacheList.size() < capacity) {//直接插入新数据
                cacheList.push_front(pair<int, int>(key, value));
                location[key] = cacheList.begin();
            }
            else {// full，去除一个旧数据后插入新数据
                int it_oldKey(cacheList.back().first);
                location.erase(it_oldKey);
                cacheList.pop_back();
                cacheList.push_front(pair<int, int>(key, value));
                location[key] = cacheList.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(2, 1);
    obj->put(1, 1);
    obj->put(2, 3);
    obj->put(4, 1);
    cout << obj->get(1) << endl;
    cout << obj->get(2) << endl;
    return 0;
}