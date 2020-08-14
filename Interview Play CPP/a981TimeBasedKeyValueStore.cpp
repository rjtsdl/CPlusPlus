//
//  a981TimeBasedKeyValueStore.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

class TimeMap {
private:
    unordered_map<string, map<int, string>> m_store;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        m_store = unordered_map<string, map<int, string>>();
    }
    
    void set(string key, string value, int timestamp) {
        m_store[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto i = m_store[key].lower_bound(-timestamp);
        if (i == m_store[key].end()) {
            return "";
        }
        return i->second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
