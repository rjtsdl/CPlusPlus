//
//  a525ContiguousArray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> count;
        
        count[0] = -1;
        int curCount = 0;
        int maxLength = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curCount += nums[i] == 1 ? 1 : -1;
            if (count.find(curCount) != count.end()) {
                maxLength = max(maxLength, i-count[curCount]);
            } else {
                count[curCount] = i;
            }
        }
        
        return maxLength;
        
    }
};
