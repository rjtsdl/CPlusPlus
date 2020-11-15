//
//  a146LRU.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <list>
#include <utility>
#include <unordered_map>

using namespace std;

class LRUCache {
    int cp;
    list<pair<int, int>> rL;
    unordered_map<int, list<pair<int, int>>::iterator> km;
public:
    LRUCache(int capacity) {
        cp = capacity;
    }
    
    int get(int key) {
        if (km.find(key) == km.end()) return -1;
        int val = km[key]->second;
        rL.erase(km[key]);
        km[key] = rL.insert(rL.end(), make_pair(key, val));
        return val;
    }
    
    void put(int key, int value) {
        if (km.find(key) == km.end() && rL.size() == cp) {
            auto kv = rL.front();
            km.erase(kv.first);
            rL.erase(rL.begin());
        }
        auto it = rL.insert(rL.end(), make_pair(key, value));
        if (km.find(key) != km.end()) {
            rL.erase(km[key]);
        }
        km[key] = it;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
