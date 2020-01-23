//
//  a1150.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        // we only have to check if the mid element is majority or not
        
        int val = target;
        
        auto lb = lower_bound(nums.begin(), nums.end(), val);
        auto ub = upper_bound(nums.begin(), nums.end(), val+1);
        
        
        return (int)(ub - lb) > nums.size()/2;
    }
};
