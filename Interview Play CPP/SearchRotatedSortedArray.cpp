//
//  SearchRotatedSortedArray.cpp
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
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
        
    }
    
    int binarySearch(const vector<int>& nums, int start, int end, int target)
    {
        if (start > end) {
            return -1;
        }
        
        int pivot = start + (end - start)/2;
        if (nums[pivot] == target) {
            return pivot;
        }
        
        if (nums[start] < nums[end]) {
            // rigth order
            if (nums[pivot] > target) {
                return binarySearch(nums, start, pivot-1, target);
            }
            else if (nums[pivot] < target)
            {
                return binarySearch(nums, pivot+1, end, target);
            }
        }
        else if (nums[start] > nums[end])
        {
            if (nums[pivot] < nums[end]) {
                if (nums[pivot] < target && target <= nums[end]) {
                    return binarySearch(nums, pivot+1, end, target);
                }
                else
                {
                    return binarySearch(nums, start, pivot-1, target);
                }
            }
            else
            {
                if (nums[start] <= target && target < nums[pivot]) {
                    return binarySearch(nums, start, pivot-1, target);
                }
                else{
                    return binarySearch(nums, pivot+1, end, target);
                }
            
            }
        }
        return -1;
        
    }
};