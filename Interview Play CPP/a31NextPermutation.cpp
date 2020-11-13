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
        if (nums.size() <= 1) return;
        int i = nums.size()-2;
        while (i>=0) {
            if (nums[i] < nums[i+1]) break;
            i--;
        }
        
        if (i <0) {reverse(nums.begin(), nums.end()); return;}
        int j = i+1;
        while (j < nums.size() && nums[j] > nums[i]) {j++;}
        swap(nums[i], nums[j-1]);
        reverse(nums.begin()+i+1, nums.end());
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
