//
//  a691StickerstoSpellWord.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/15/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int findNextStatus(int status, string target, string str)
    {
        int n=target.size();
        for(auto& ch:str)
        {
            for(int i=0;i<n;i++)
            {
                if((((status>>i)&1)==0) && (ch==target[i]))
                {
                    status+=(1<<i);
                    break;
                }
            }
        }
        return status;
    }
    int minStickers(vector<string>& stickers, string target) {
        int n=target.size();
        int len=(1<<n);
        vector<int> dp(len,INT_MAX/2); // the minimum number of stickers to spell status i
        dp[0]=0;
        for(int i=0;i<len;i++)
        {
            if(dp[i]==INT_MAX/2) continue;
            for(auto& x:stickers)
            {
                int j=findNextStatus(i,target, x); // next status
                dp[j]=min(dp[j],dp[i]+1);
            }
        }

        return dp[len-1]==INT_MAX/2 ? -1:dp[len-1];

    }
};
