//
//  MajorityElement.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 10/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

// Description:
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

// Thought:
// This will be equivalent with the question of find the median number, except you need to deal with dups
// 1. implement find kth element in a vector
// 2. take k as n/2 should be always good

// [2, 2, 1, 1, 1, 2, 2]
// [1, 2, 1, 1, 2, 2, 2]
// [1, 1, 1, 2, 2, 2, 2]

#include <iostream>
#include <vector>
using namespace std;


class MajorityElement
{
public:
    int majorityElement(vector<int>& nums) {
        int medianPos = (int)nums.size()/2;
        return findKthElement(nums, 0, (int)nums.size(), medianPos);
    }
    
    int findKthElement(vector<int>& nums, int start, int end, int k)
    {
        // randomly pick a number [start, end)
        int randPos = start + (end - start)/2;
        int pivot = nums[randPos];
        
        int left = start;
        int right = end - 1;
        
        while (left < right)
        {
            // left advance
            while (nums[left] < pivot) { left++; }
            // right advance
            while (nums[right] > pivot) { right--; }
            
            if (nums[left] == pivot && nums[right] == pivot && left < right) {
                // For this situation, the moving stuck, we need to swap something out between left and right
                nums[left] = findSomethingSmallerAndSwap(nums, left+1, right, pivot);
                nums[right] = findSomethingGreaterAndSwap(nums, left+1, right, pivot);
                if (nums[left] == pivot && nums[right] == pivot) {
                    // Sort of done
                    break;
                }
            }
            else if (left < right)
            {
                // Swap left and right, and wait for another run
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
            else
            {
                // do nothing, let the outter while loop exit
            }
        }
        // We find kth
        if (start + k >= left && start + k <= right)
        {
            return pivot;
        }
        else if (start + k  < left)
        {
            return findKthElement(nums, start, left, k);
        }
        else if (start + k > right)
        {
            return findKthElement(nums, right+1, end, start + k - right - 1);
        }
        else
        {
            // Should not fall in here
        }
        // Should return before here
        return -1;
    }
    
    int findSomethingGreaterAndSwap(vector<int>& nums, int start, int end, int pivot)
    {
        for (int i = start; i < end; ++i)
        {
            if (nums[i] > pivot) {
                int ret = nums[i];
                nums[i] = pivot;
                return ret;
            }
        }
        return pivot;
    }
    
    int findSomethingSmallerAndSwap(vector<int>& nums, int start, int end, int pivot)
    {
        for (int i = start; i < end; ++i)
        {
            if (nums[i] < pivot) {
                int ret = nums[i];
                nums[i] = pivot;
                return ret;
            }
        }
        return pivot;
    }
};
/*
int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    MajorityElement obj;
    cout<< obj.majorityElement(nums)<<endl;
    return 0;
}
 */



// 1 2 3 7 7 3 5 7 8 9 10
