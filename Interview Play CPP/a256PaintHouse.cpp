//
//  a256PaintHouse.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/29/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) {
                return 0;
            }
            
            int k = (int)costs.front().size();
            if (k<=1) {
                return k==0 ? 0 : costs[0][0];
            }
            
            
            vector<int> prev(k, 0);
            vector<int> minExc(k, 0);
            vector<int> cur(k, 0);
            
            for (int i =0; i < costs.size(); ++i) {
                minExcept(prev, minExc);
                for (int j =0; j < k; ++j) {
                    cur[j] = minExc[j] + costs[i][j];
                }
                prev = cur;
            }
            
            return *min_element(prev.begin(), prev.end());
            
            
            
        }
        
        void minExcept(vector<int>& input, vector<int>& output) {
            fill(output.begin(), output.end(), INT_MAX);
            
            for (int i=1; i < input.size(); ++i) {
                output[i] = min(output[i-1], input[i-1]);
            }
            
            int R = input.back();
            for (int i=(int)input.size()-2; i >=0 ; --i) {
                output[i] = min(output[i], R);
                R = min(R, input[i]);
            }
        }
};
