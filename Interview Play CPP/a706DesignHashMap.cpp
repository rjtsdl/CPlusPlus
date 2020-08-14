//
//  a706DesignHashMap.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class MyHashMap {
private:
    vector<vector<vector<int>>> m_linkedList;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        // 571 just a random prime number
        m_linkedList = vector<vector<vector<int>>>(571);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = key % m_linkedList.size();
        auto& v = m_linkedList[pos];
        
        for(auto i = v.begin(); i != v.end(); i++) {
            if ((*i)[0] == key) {
                v.erase(i);
                break;
            }
        }
        
        v.push_back({key, value});
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = key % m_linkedList.size();
        auto& v = m_linkedList[pos];
        
        for(auto i = v.begin(); i != v.end(); i++) {
            if ((*i)[0] == key) {
                return (*i)[1];
            }
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = key % m_linkedList.size();
        auto& v = m_linkedList[pos];
        
        for(auto i = v.begin(); i != v.end(); i++) {
            if ((*i)[0] == key) {
                v.erase(i);
                break;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
