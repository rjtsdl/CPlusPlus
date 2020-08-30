//
//  a1480RunningSumOf1DayArray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSum(nums.size());
        if (nums.size() == 0) return runningSum;
        runningSum[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            runningSum[i] = runningSum[i-1] + nums[i];
        }
        
        return runningSum;
    }
};
