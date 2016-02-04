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
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        vector<vector<int>> ret;
        do
        {
            ret.push_back(sortedNums);
        }
        while (IncrementVectorByJustOneStep(sortedNums));
        return ret;
    }
    
    // Need to remember using reference here.
    bool IncrementVectorByJustOneStep(vector<int>& sortedNums)
    {
        int len = (int)sortedNums.size();
        int thePos = len - 1;
        for (int i = len - 1; i >= 0; --i) {
            if (i-1 >= 0 && sortedNums[i-1] < sortedNums[i]) {
                thePos = i - 1;
                break;
            }
        }
        reverse(sortedNums.begin() + thePos + 1, sortedNums.end());
        if (thePos == len - 1) {
            return false;
        }
        
        for (int j = thePos + 1; j < len; ++j) {
            if (sortedNums[j] > sortedNums[thePos]) {
                int temp = sortedNums[j];
                sortedNums[j] = sortedNums[thePos];
                sortedNums[thePos] = temp;
                break;
            }
        }
        return true;
    }
};

/*
int main()
{
    vector<int> nums = {1, 2};
    Solution sol;
    sol.permuteUnique(nums);
    return 0;
}
*/