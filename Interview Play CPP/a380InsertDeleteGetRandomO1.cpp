//
//  a380InsertDeleteGetRandomO1.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>

class RandomizedSet {
public:
    vector vec;
    unordered_map mp;
    /** Initialize your data structure here. */
    RandomizedSet() {
                
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val) > 0) return false;
        vec.push_back(val);
        mp.insert(make_pair(val, vec.size()-1));
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val) == 0) return false;
        auto itr = mp.find(val);
        int pos = itr->second;
        
        vec[pos] = vec[vec.size()-1];
        mp[vec[pos]] = pos;
        
        mp.erase(itr);
        vec.erase(vec.end()-1);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return (vec[rand() % vec.size()]);
    }
};
