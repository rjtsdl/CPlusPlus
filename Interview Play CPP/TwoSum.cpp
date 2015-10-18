//
//  TwoSum.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 10/18/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class TwoSum
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapForNums;
        mapForNums.clear();
        for (int i = 0; i < nums.size() ; ++i)
        {
            mapForNums.insert(make_pair(nums[i], i+1));
        }
        
        for (int i = 0; i < nums.size() ; ++i)
        {
            int lookingfor = target - nums[i];
            const auto& iter =mapForNums.find(lookingfor);
            if (iter != mapForNums.end() && i+1 != iter->second)
            {
                
                return vector<int>({min(i+1, iter->second) , max(i+1, iter->second)});
            }
        }
        
        
        return vector<int>();
    }
};
/*

int main()
{
    vector<int> nums = {2,7, 9,11};
    TwoSum ts;
    ts.twoSum(nums, 9);
    
}
 */
