//
//  RemoveDuplicatesfromSortedArrayII.cpp
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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int cur = nums[0];
        int count = 1;
        for(int i =1 ; i < nums.size();)
        {
            if (nums[i] != cur)
            {
                cur = nums[i];
                count = 1;
                i++;
                continue;
            }
            
            if(nums[i] == cur)
            {
                if (count < 2)
                {
                    count++;
                    i++;
                    continue;
                }
                else
                {
                    nums.erase(nums.begin() + i);
                }
            }
        }
        
        return (int)nums.size();
    }
};