//
//  a1048LongestStringChain.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int check(string s, string t){
        int m = s.length(), n = t.length(), i = 0, j = 0, missing = 0;
        if(n != m+1) return false;
        for(int i=0; i<n; i++){
            if(t[i] == s[j]) j++;
            else{
            // if no character is missing, continue to check
            // if we found a missing character, update the variable
                if(!missing) missing = 1;
                // if number of missing character is >=2 return false
                else return false;
            }
        }
        return true;
    }
    
    static bool cmp(const string& s, const string t){
        return s.length() < t.length();
    }
    
    int longestStrChain(vector<string>& v) {
        if(v.empty()) return 0;
        sort(v.begin(), v.end(), cmp);
        vector<int> dp(v.size(), 1);
        int ans = 0;
        for(int i=1; i<v.size(); i++){
            for(int j=0; j<i; j++){
                int x = v[i].length(), y = v[j].length();
                if(y+1 == x && check(v[j], v[i]) && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
