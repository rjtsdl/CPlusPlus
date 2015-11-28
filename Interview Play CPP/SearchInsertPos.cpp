//
//  SearchInsertPos.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/27/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchJustGreaterOrEqual(nums, 0, nums.size(), target);
        
    }
    
    int searchJustGreaterOrEqual(vector<int>& nums, int start, int end, int target)
    {
        int pivot = start +(end - start)/2;
        
        if (start >= nums.size()) {
            return nums.size();
        }
        
        if (end < 0) {
            return 0;
        }
        
        if (start == end) {
            if (nums[start] >= target) {
                return start;
            }
            return start + 1;
        }
        
        
        if (nums[pivot] >= target) {
            return searchJustGreaterOrEqual(nums, start, pivot, target);
        }
        
        if (nums[pivot] < target) {
            return searchJustGreaterOrEqual(nums, pivot+1, end, target);
        }
        return 0;
    }
};