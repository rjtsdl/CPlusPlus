//
//  SearchinRotatedSortedArrayII.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/12/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool search(vector<int>& nums, int target)
    {
        return search(nums, target, 0, (int)nums.size());
    }
    bool search(vector<int>& nums, int target, int left, int right) {
        while (right - left > 1) {
            int pivot = left + (right - left)/2;
            if (target  == nums[pivot]) {
                return true;
            }
            
            if (target > nums[pivot])
            {
                if (nums[pivot] > nums[left] || nums[pivot] > nums[right -1]) {
                    left = pivot +1;
                    continue;
                }
                
                if (nums[pivot] < nums[left] || nums[pivot] < nums[right - 1]) {
                    
                    if (nums[right -1] == target) {
                        return true;
                    }
                    else if(nums[right-1] > target)
                    {
                        left = pivot +1;
                    }
                    else
                    {
                        right =  pivot;
                    }
                    
                    continue;
                }
                
                return search(nums, target, left + 1, pivot) || search(nums, target, pivot+1, right);
                
            }
            else if (target < nums[pivot])
            {
                if (nums[pivot] < nums[right-1] || nums[pivot] < nums[left]) {
                    right = pivot;
                    continue;
                }
                
                if (nums[pivot] > nums[left] || nums[pivot] > nums[right - 1]) {
                    if (target == nums[left]) {
                        return true;
                    }
                    else if (target < nums[left])
                    {
                        left = pivot + 1;
                    }
                    else
                    {
                        right = pivot;
                    }
                    continue;
                }
                
                return search(nums, target, left + 1, pivot) || search(nums, target, pivot+1, right);
            
            }
            
        }
        if (right - left == 1) {
            if(target == nums[left])
            {
                return true;
            }
        }
        
        return false;
        
    }
};