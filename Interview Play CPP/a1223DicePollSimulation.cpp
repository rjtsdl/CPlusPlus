//
//  a1223DicePollSimulation.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int dp[5005][9][20];
    int recur(int x,int last,int occ,vector<int>& rollmax)
    {
        if(x==0)
            return 1;
        if(dp[x][last][occ]!=-1)
            return dp[x][last][occ];
        int ans=0;
        for(int i=1;i<=6;i++)
        {
            if(i==last && occ<rollmax[i-1])
                ans+=(recur(x-1,i,occ+1,rollmax)%mod);
            else if(i==last && occ==rollmax[i-1])
                continue;
            else if(i!=last && rollmax[i-1]>=1)
                ans+=(recur(x-1,i,1,rollmax)%mod);
            ans=ans%mod;
        }
        return dp[x][last][occ]=ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return recur(n,7,0,rollMax);
    }
};
