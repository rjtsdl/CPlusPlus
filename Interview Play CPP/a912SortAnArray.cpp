//
//  a912SortAnArray.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/7/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int helper(vector<int> &nums,int low,int high)
    {
        int p=nums[high];
        int i=low-1;
        for(int j=low;j<high;j++)
        {
            if(nums[j]<p)
            {
                i++;
                swap(nums[j],nums[i]);
            }
        }

        swap(nums[i+1],nums[high]);
        return i+1;
    }

    void quicksort(vector<int> &nums,int low,int high)
    {
        if(low<high)
        {
            int p=helper(nums,low,high);

            quicksort(nums,low,p-1);
            quicksort(nums,p+1,high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        int n=nums.size();
        quicksort(nums,0,n-1);
        return nums;
    }
};
