//
//  NextPermutation.cpp
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
    void nextPermutation(vector<int>& nums) {
        // find the first not in ascending order
        int lastIndex = (int)nums.size() - 1;
        while (lastIndex >= 0) {
            if (lastIndex + 1 < nums.size()) {
                if (nums[lastIndex] < nums[lastIndex+1]) {
                    break;
                }
            }
            lastIndex--;
        }
        
        // If out of index, then reverse
        if (lastIndex < 0) {
            reverse(nums, 0);
            return;
        }
        
        // Else, swap one and one just greater, then reverse
        int start = lastIndex;
        lastIndex++;
        while (lastIndex < nums.size()) {
            if (nums[lastIndex] <= nums[start]) {
                break;
            }
            lastIndex++;
        }
        lastIndex--;
        
        int temp = nums[start];
        nums[start] = nums[lastIndex];
        nums[lastIndex] = temp;
        // Should not possible for lastIndex > size
        reverse(nums, start+1);
    }
    
    void reverse(vector<int>& nums, int start)
    {
        int lastIndex = (int)nums.size() - 1;
        
        while (start < lastIndex) {
            int temp = nums[start];
            nums[start] = nums[lastIndex];
            nums[lastIndex] = temp;
            start++;
            lastIndex--;
        }
    }
};

/*
int main()
{
    Solution sol;
    vector<int> nums = {3,2,1};
    sol.nextPermutation(nums);
}
 */
