//
//  CombinationSumII.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 1/24/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

// Key point of this solution:
// 1. convert candidates to a map
// 2. divide into two problem: at least vs nothing
// 3. stop early if no possible solution could be generated
// 4. careful about the reference
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> rearranged;
        for (int cand: candidates) {
            if (rearranged.find(cand) == rearranged.end()) {
                rearranged[cand] = 1;
            }
            else
            {
                rearranged[cand]++;
            }
        }
        return combinationSum2(rearranged, target);
    }
    
    vector<vector<int>> combinationSum2(map<int, int>& candidates, int target)
    {
        vector<vector<int>> ret;
        if (target == 0) {
            // get a match
            ret.push_back(vector<int>{});
            return ret;
        }
        if (target < 0 || candidates.empty()) {
            return ret;
        }
        auto cand = *candidates.rbegin();
        if (cand.second > 0) {
            candidates[cand.first]--;
            if (candidates[cand.first] == 0) {
                candidates.erase(cand.first);
            }
            // Test out the combination include at least once of cand.first
            vector<vector<int>> subRet = combinationSum2(candidates, target - cand.first);
            if (!subRet.empty()) {
                for (auto& sub : subRet) {
                    sub.push_back(cand.first);
                    ret.push_back(sub);
                }
            }
            candidates[cand.first] = cand.second;
            // And test out the combination without cand.first
            candidates.erase(cand.first);
            vector<vector<int>> subRet2 = combinationSum2(candidates, target);
            if (!subRet2.empty()) {
                for (auto& sub2 : subRet2) {
                    ret.push_back(sub2);
                }
            }
            candidates[cand.first] = cand.second;
        }
        return ret;
    
    }
};