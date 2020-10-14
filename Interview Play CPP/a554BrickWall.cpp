//
//  a554BrickWall.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        for (int i = 0; i < wall.size(); i++) {
            int acc = 0;
            for (int j =0 ; j < wall[i].size()-1; j++) {
                acc += wall[i][j];
                mp[acc] = mp[acc] + 1;
            }
        }
        int bd = 0;
        for (auto kv : mp){
            bd = max(kv.second, bd);
        }
        
        return wall.size() - bd;
        
    }
};
