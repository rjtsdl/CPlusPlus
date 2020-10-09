//
//  a1296DivideArrayinSetsofKConsecutiveNumbers.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/9/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int size = nums.size();
         if(size % k != 0)
             return false;
        int count = 0;
        map<int,int> mp;
       
        for(int i = 0; i < size; i++)
        {
         mp[nums[i]]++;
        }
        for(auto x: mp)
        {
            if(x.second)
            {
                int freq = x.second;
                int curr = x.first;
                while(count < k)
                {
                    if(mp[curr+count] >= freq)
                    {
                        mp[curr+count]-= freq;
                        count++;
                    }
                    else
                        return false;
                }
                if(count == k)
                    count = 0;
            }
        }
        return true;
    }
};
