//
//  MaximumSubarray.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/2/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalTotal = INT_MIN;
        int subTotal = 0;
        int j = 0;
        while (j < nums.size()) {
            subTotal += nums[j];
            ++j;
            if (subTotal > globalTotal) {
                globalTotal = subTotal;
            }
            
            subTotal = max(subTotal, 0);
        }
        return globalTotal;
    }
};
