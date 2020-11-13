//
//  PermutationII.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 2/3/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        do {
            ret.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ret;
    }
}

/*
int main()
{
    vector<int> nums = {1, 2};
    Solution sol;
    sol.permuteUnique(nums);
    return 0;
}
*/
