//
//  a532KdiffPairsinanArray.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 11/10/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        
        int i = 0;
        int j = 1;
        int diff;
        int count = 0;
        while (j < nums.size() && i < nums.size()) {
            diff = nums[j] - nums[i];
            if (diff < k || j >= i) {
                j++;
            } else (diff > k) {
                i++;
            } else {
                count++;
                i = nextI(nums, i);
            }
        }
        
        return count;
    }
    
    int nextI(vector<int>& nums, int j) {
        int n = nums[j++];
        while (j<nums.size() && nums[j] == n) j++;
        return j;
    }
};
