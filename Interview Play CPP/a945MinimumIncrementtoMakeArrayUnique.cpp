//
//  a945MinimumIncrementtoMakeArrayUnique.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int, int> count;
        for (int a : A) count[a]++;
        
        int ans = 0;
        list<vector<int>> dups;
        int level = -1;
        
        for (auto it = count.begin(); it != count.end(); it++) {
            while (level < it->first && !dups.empty()) {
                ans += level - dups.front()[0];
                level++;
                dups.front()[1]--;
                if (dups.front()[1] == 0) {
                    dups.pop_front();
                }
            }
            level = it->first;
            if (it->second >= 2) {
                dups.push_back({it->first, it->second-1});
            }
            level++;
        }
        
        while (!dups.empty()) {
            ans += level - dups.front()[0];
            level++;
            dups.front()[1]--;
            if (dups.front()[1] == 0) {
                dups.pop_front();
            }
        }
        
        return ans;
    }
};
