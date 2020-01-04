//
//  a370RangeAddition.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> changes(length+1, 0);
        for(auto v : updates) {
            changes[v[0]] += v[2];
            changes[v[1]+1] -= v[2];
        }
        
        int var = 0;
        for (int i = 0; i < changes.size(); ++i) {
            var += changes[i];
            changes[i] = var;
        }
        
        changes.pop_back();
        return changes;
    }
};
