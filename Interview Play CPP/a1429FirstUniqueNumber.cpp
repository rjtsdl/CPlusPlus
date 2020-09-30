//
//  a1429FirstUniqueNumber.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <queue>

class FirstUnique {
public:
    unordered_map<int,int> mp;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(int num : nums){
            mp[num]++;
            q.push(num);
        }
    }
    int showFirstUnique() {
        while(!q.empty()){
            if(mp[q.front()] == 1){
                return q.front();
            }
            q.pop();
        }
        return -1;
    }
    void add(int value) {
        mp[value]++;
        q.push(value);
    }
};
