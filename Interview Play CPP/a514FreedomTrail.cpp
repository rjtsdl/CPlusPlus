//
//  a514FreedomTrail.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/6/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &ring, string &key, int i, int p) // p is for current posn of ring, i for key
    {
        if(i==key.length())
            return 0;
        int tmp=0;
        // if already solved, return dp
        
        if(dp[p][i]!=-1)
            return dp[p][i];
        
        int n=ring.size();
        int ans=0;
        // finding first occurence on the right
        while(tmp<n)
        {
            if(ring[(p+tmp)%n]==key[i])
            {
                ans+=(tmp+solve(ring,key,i+1,(p+tmp)%n));
                break;
            }
            tmp++;
        }
        tmp=n-1;
        // finding first occurence on the left
        while(tmp>=0)
        {
            if(ring[(p+tmp)%n]==key[i])
            {
                ans=min(ans,(n-tmp)+solve(ring,key,i+1,(p+tmp)%n));  // taking min of both
                break;
            }
            tmp--;
        }
        return dp[p][i]=ans;
    }
    
    int findRotateSteps(string ring, string key) {
        dp=vector<vector<int>>(ring.length()+1,vector<int>(key.length()+1,-1));
        int ans=solve(ring,key,0,0);
        ans+=key.length();
        return ans;
    }
};
