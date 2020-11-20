//
//  a403FrogJump.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_map<int, unordered_set<int>> mp;
public:
    bool canCross(vector<int>& stones) {
        for (int s: stones) {
            mp[s] = {};
        }
        
        mp[0].insert(1);
        
        for (int s: stones) {
            for (int j: mp[s]) {
                if (mp.find(s+j) != mp.end()) {
                    mp[s+j].insert({j-1, j, j+1});
                }
            }
        }
        
        return !mp[stones.back()].empty();
    }
};
