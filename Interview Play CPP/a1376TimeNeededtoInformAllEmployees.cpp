//
//  a 1376TimeNeededtoInformAllEmployees.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/12/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> dp(n, -1);
        dp[headID]=0;

        for(int i =0; i < n; i++) {
            if(dp[i] == -1) {
                computeTimeDP(i, dp, manager, informTime);
            }
        }
        
        int maxTime=-1;
        for(int i=0;i<n;i++) {
            maxTime = max(maxTime, dp[i]);
        }
        
        return maxTime;
    }
    
    void computeTimeDP(int i, vector<int>& dp, vector<int>& manager, vector<int>& informTime) {
        int managerId = manager[i];
        if (dp[managerId] == -1) {
            computeTimeDP(managerId, dp, manager, informTime);
        }
        
        dp[i] = informTime[managerId] + dp[managerId];
        return;
    }
};
