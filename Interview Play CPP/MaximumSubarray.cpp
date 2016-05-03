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
        int globalI = 0, globalJ = 0;
        int subTotal = 0;
        int i =0 , j = 0;
        while (i <= j && j < nums.size()) {
            subTotal += nums[j];
            ++j;
            if (subTotal > globalTotal) {
                globalTotal = subTotal;
                globalI = i;
                globalJ = j;
            }
            
            if (subTotal <= 0) {
                i = j;
                subTotal = 0;
            }
        }
        return globalTotal;
    }
};