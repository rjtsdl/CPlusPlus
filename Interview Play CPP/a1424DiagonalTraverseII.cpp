//
//  a1424DiagonalTraverseII.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/10/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ret;
        priority_queue<vector<int>> pq;
        
        // index 0: -sum(i+j), index 1: i, index 2: val
        
        if (nums.empty() || nums[0].empty()) {
            return ret;
        }
        
        pq.push(vector<int>{0, 0, nums[0][0]});
        nums[0][0] = 0;
        
        while (!pq.empty()) {
            vector<int> top = pq.top();
            int i = top[1];
            int j = -(top[0] + top[1]);
            ret.push_back(top[2]);
            pq.pop();
            
            if (i+1 < nums.size() && j < nums[i+1].size() && nums[i+1][j] != 0) {
                pq.push(vector<int>{-(i+1+j), i+1, nums[i+1][j]});
                nums[i+1][j] = 0;
            }
            
            if (j + 1 < nums[i].size() && nums[i][j+1] != 0) {
                pq.push(vector<int>{-(i+1+j), i, nums[i][j+1]});
                nums[i][j+1] = 0;
            }
        }
        
        return ret;
        
    }
};
