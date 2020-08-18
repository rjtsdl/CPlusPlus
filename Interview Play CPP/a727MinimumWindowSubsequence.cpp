//
//  a727MinimumWindowSubsequence.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        vector<vector<int>> dp(2, vector<int>(S.size(), -1));

        for (int i = 0; i < S.size(); ++i)
            if (S[i] == T[0]) {
                dp[0][i] = i;
            }

        /*At time j when considering T[:j+1],
          the smallest window [s, e] where S[e] == T[j]
          is represented by dp[j & 1][e] = s, and the
          previous information of the smallest window
          [s, e] where S[e] == T[j-1] is stored as
          dp[~j & 1][e] = s.
        */
        for (int j = 1; j < T.size(); ++j) {
            int last = -1;
            //Now we would like to calculate the candidate windows
            //"dp[j & 1]" for T[:j+1].  'last' is the last window seen.
            for (int i = 0; i < S.size(); ++i) {
                dp[j&1][i] = -1;
                if (last >= 0 && S[i] == T[j]) dp[j & 1][i] = last;
                if (dp[~j & 1][i] >= 0) last = dp[~j & 1][i];
            }
        }

        //Looking at the window data dp[~T.length & 1],
        //choose the smallest length window [s, e].
        int start = 0, end = S.size();
        for (int e = 0; e < S.size(); ++e) {
            int s = dp[~T.size() & 1][e];
            if (s >= 0 && e - s < end - start) {
                start = s;
                end = e;
            }
        }
        return end < S.size() ? S.substr(start, end + 1 - start) : "";
    }
};
