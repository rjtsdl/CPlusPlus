//
//  a568MaximumVacationDays.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/21/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = days.size();
        int K = days[0].size();
        
        vector<vector<int>> dp (N, vector<int>(K+1, 0));
        
        for (int k = K; k >= 0; k--) {
            for (int i =0; i < N; i++) {
                if (k == K) {
                    dp[i][k] = 0;
                    continue;
                }
                
                dp[i][k] = days[i][k] + dp[i][k+1];
                
                for (int j =0; j <N; j++) {
                    dp[i][k] = max(dp[i][k], flights[i][j] * (days[j][k] + dp[j][k+1]));
                }
            }
        }
        
        return dp[0][0];
    }
};
