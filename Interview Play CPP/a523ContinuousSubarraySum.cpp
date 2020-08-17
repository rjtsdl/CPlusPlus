//
//  a523ContinuousSubarraySum.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        k = k == 0 ? INT_MAX : k;
        unordered_map<int,int> um;
        int sum = 0;
        um[0] = -1; //To handle cases like [0,0] which is a valid answer
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(um.find(sum % k) != um.end()){
                if(i - um[sum % k] > 1)    // at least 2 elemet
                    return true;
            }else{
                um[sum%k] = i;
            }
        }
        return false;
    }
};
