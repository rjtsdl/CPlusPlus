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
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        return (int)(ub - lb) > nums.size()/2;
    }
};
