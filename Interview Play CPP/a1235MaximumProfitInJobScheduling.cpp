//
//  a1235MaximumProfitInJobScheduling.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size(),i;
        vector< pair<int,int> >v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({startTime[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> dp(n,0);
        
        for(i=n-1;i>=0;i--)
        {
            int f= v[i].first;
            int ii=v[i].second;
            int val=0;
            
            val+=profit[ii];
            
            int x= endTime[ii];
            
            auto it= lower_bound(v.begin(),v.end(),x,[](const pair<int,int> &p, const int &value){
                return p.first<value;
            });       //searching for next Starttime which is greater than the current endtime
            
            if(it!=v.end())
            {
                int j=it-v.begin();
                
                val+=dp[j];
            }
            
            if(i==n-1) {
                dp[i]=max(dp[i],val);
            } else {
                dp[i]=max(dp[i],max(val, dp[i+1]));//either take the ith job or skip it and take the next one
            }
        }
        
        return dp[0];
    }
};
