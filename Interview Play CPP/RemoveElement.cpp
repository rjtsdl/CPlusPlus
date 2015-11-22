//
//  RemoveElement.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/21/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int countSofar = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                ++countSofar;
            }
            else
            {
                nums[i-countSofar] = nums[i];
            }
        }
        return (int)nums.size() - countSofar;
    }
};
