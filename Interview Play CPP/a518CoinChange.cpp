//
//  a518CoinChange.cpp
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
    int dp[501][5001];
    int chan(int amount, vector<int>& coins,int n){
        if(dp[n][amount]!=-1)return dp[n][amount];
        if(amount==0){return 1;}
        if(n==0)return 0;
        if(coins[n-1]<=amount){
            return dp[n][amount]=chan(amount,coins,n-1)+chan(amount-coins[n-1],coins,n);
        }
        else {return dp[n][amount]=chan(amount,coins,n-1);}
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return chan(amount,coins,coins.size());
    }
};
