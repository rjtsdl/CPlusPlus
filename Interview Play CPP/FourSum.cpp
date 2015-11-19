//
//  FourSum.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 11/15/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    /* Time perf not good
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        // Make a structure of tuples and their two sum (index1, index2, sumof1and2)
        vector<vector<int>> map;
        
        for (int j = 1; j < nums.size(); j++) {
            for ( int i = 0; i < j; i++)
            {
                map.push_back(vector<int>{i, j, nums[i] + nums[j]});
            }
        }
        sort(map.begin(), map.end(), [](vector<int> A, vector<int> B){
            if (A[2] < B[2]) {
                return true;
            }
            else
            {
                return false;
            }
        });
        
        //Two sum here, be remember to compare the conflict ones
        //Dups ?
        
        int a = 0;
        int b = (int)map.size() - 1;
        
        while (a < b) {
            if (map[a][2] + map[b][2] == target)
            {
                //Check any conflict
                if (map[a][0] > map[b][1])
                {
                    ret.push_back(vector<int>{nums[map[b][0]], nums[map[b][1]], nums[map[a][0]], nums[map[a][1]]});
                }
                else if (map[a][1] < map[b][0])
                {
                    ret.push_back(vector<int>{nums[map[a][0]], nums[map[a][1]], nums[map[b][0]], nums[map[b][1]]});
                }
                ++a;
            }
            else if (map[a][2] + map[b][2] < target)
            {
                ++a;
            }
            else if (map[a][2] + map[b][2] > target)
            {
                --b;
            }
        }
        return ret;
    }
     */
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > res;
        unordered_map<int, vector<pair<int, int> > >pairs;
        pairs.reserve(n*n);
        sort(num.begin(), num.end());
        for(int i = 0; i < n; i++)
            for(int j = i+1 ; j < n; j++)
                pairs[num[i]+num[j]].push_back(make_pair(i,j));
        
        for(int i = 0; i < n - 3; i++)
        {
                if(i != 0 && num[i] == num[i-1])continue;//防止第一个元素重复
                for(int j = i+1; j < n - 2; j++)
                {
                        if(j != i+1 && num[j] == num[j-1])continue;//防止第二个元素重复
                        if(pairs.find(target - num[i] - num[j]) != pairs.end())
                        {
                                vector<pair<int, int>> &sum2 = pairs[target - num[i] - num[j]];
                                bool isFirstPush = true;
                                for(int k = 0; k < sum2.size(); k++)
                                    {
                                        if(sum2[k].first <= j)continue;//保证所求的四元组的数组下标是递增的
                                        if(isFirstPush || (res.back())[2] != num[sum2[k].first])
                                            {
                                                res.push_back(vector<int>{num[i], num[j], num[sum2[k].first], num[sum2[k].second]});
                                                isFirstPush = false;
                                            }
                                        }
                                }
                        }
                }
        
        return res;
        }
};

/*
int main(int argc, const char * argv[]) {
    
    vector<int> input = {-3, -2, -1, 0, 0, 1, 2, 3};
    int target = 0;
    Solution sol;
    vector<vector<int>> ret = sol.fourSum(input, target);
    return 0;
    
}
 */



