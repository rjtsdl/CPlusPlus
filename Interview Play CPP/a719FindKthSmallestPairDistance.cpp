//
//  a719FindKthSmallestPairDistance.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/23/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.back();
        
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            int left = 0;
            int count = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mid) ++left;
                count += right-left;
            }
            
            if (count >= k) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};
