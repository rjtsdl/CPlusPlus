//
//  FirstMissingPositive.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 1/24/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int largest = nums.size();
        for (auto& num : nums) {
            if (num <= 0 || num > largest) {
                num = largest + 1;
            }
        }
        for (int i = 0; i< nums.size();i++) {
            if (abs(nums[i]) <= largest) {
                //This one should have a position
                //Mark it with negative number
                int rightPos = abs(nums[i]) - 1;
                nums[rightPos] = -abs(nums[rightPos]);
            }
        }
        
        int ret = largest + 1;
        for (int i = 0; i< nums.size(); i++)
        {
            if (nums[i] >= 0) {
                //Missing i+1
                ret = i+1;
                break;
            }
        }
        return ret;
    }
};
