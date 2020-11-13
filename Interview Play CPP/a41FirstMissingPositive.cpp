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
        int i=0, n=nums.size();
        while(i<n) {
            if(nums[i]>0 && nums[i]-1<n && nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1], nums[i]);
            else i++;
        }
        int missing = 1;
        for(int num:nums) if(num==missing) missing++;
        return missing;
    }
};
