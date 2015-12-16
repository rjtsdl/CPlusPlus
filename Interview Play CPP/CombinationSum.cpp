//
//  CombinationSum.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 12/15/15.
//  Copyright © 2015 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return worker(candidates, target);
        
    }
    
    // assumption, no dup in candidates
    vector<vector<int>> worker(vector<int>& candidates, int target) {
        if (candidates.empty() || target == 0) {
            return vector<vector<int>>();
        }
        int lastOne = *(candidates.rbegin());
        candidates.pop_back();
        vector<vector<int>> res;
        
        for (int i =0; lastOne * i <= target; i++) {
            vector<vector<int>> subRes = worker(candidates, target - i *lastOne);
            if (!subRes.empty()) {
                for (auto& sol : subRes) {
                    for (int j = 0; j<i; j++) {
                        sol.push_back(lastOne);
                    }
                }
                res.insert(res.end(), subRes.begin(), subRes.end());
            }
            else if (lastOne * i == target)
            {
                vector<int> theOnes;
                for (int j =0; j < i; j++) {
                    theOnes.push_back(lastOne);
                }
                if (!theOnes.empty()) {
                    res.push_back(theOnes);
                }
            }
            
        }
        // recursive, need to maintain the one shared by each step
        candidates.push_back(lastOne);
        return res;
    }
};