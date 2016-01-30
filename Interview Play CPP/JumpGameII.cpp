//
//  JumpGameII.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 1/30/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        // Range concept is important
        // Step 1 reached area must be continuous
        // Step 1 and step 2 reached area must be adjacent
        if (nums.size() <= 1) {
            return 0;
        }
        int head = 0;
        int tail = nums[0];
        int step = 1;
        
        while (tail < nums.size() - 1) {
            int newTail = tail;
            for (int i = head + 1; i <= tail; ++i) {
                newTail = max(newTail, nums[i] + i);
            }
            head = tail;
            tail = newTail;
            step++;
            if (head >= tail) {
                break;
            }
        }
        return step;
        
    }
};
