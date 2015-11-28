//
//  SearchForARange.cpp
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        if (nums.empty() || nums.front() > target || nums.back() < target) {
            return {-1, -1};
        }
        
        res.push_back(searchBinaryLeft(nums, 0, nums.size()-1, target));
        res.push_back(searchBinaryRight(nums, 0, nums.size()-1, target));
        return res;
    }
    
    int searchBinaryLeft(vector<int>& nums, int start, int end, int target)
    {
        if (start > end) {
            return -1;
        }
        
        if (start == end) {
            if (nums[start] == target) {
                return start;
            }
            return -1;
        }
        
        int pivot = start + (end - start)/2;
        if (nums[pivot] == target) {
            return searchBinaryLeft(nums, start, pivot, target);
        }
        
        if (nums[pivot] < target) {
            return searchBinaryLeft(nums, pivot+1, end, target);
        }
        
        if (nums[pivot] > target) {
            return searchBinaryLeft(nums, start, pivot-1, target);
        }
        
        return -1;
        
    }
    
    int searchBinaryRight(vector<int>& nums, int start, int end, int target)
    {
        if (start > end) {
            return -1;
        }
        
        if (start == end) {
            if (nums[start] == target) {
                return start;
            }
            return -1;
        }
        
        int pivot = end - (end - start)/2;
        if (nums[pivot] == target) {
            return searchBinaryRight(nums, pivot, end, target);
        }
        
        if (nums[pivot] < target) {
            return searchBinaryRight(nums, pivot+1, end, target);
        }
        
        if (nums[pivot] > target) {
            return searchBinaryRight(nums, start, pivot-1, target);
        }
        
        return -1;
        
    }
};

/*
int main()
{
    Solution sol;
    vector<int> nums = {1,3};
    sol.searchRange(nums, 1);
}
*/