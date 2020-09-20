//
//  a471EncodeStringwithShortestLength.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Here is a better explanation
/*https://leetcode.com/problems/encode-string-with-shortest-length/discuss/774117/use-t%2Bt.find(t1)-or-KMP-prefix-finding-two-methods-python-with-explanation
 */
    string encode(const string& s) {
        if(s.size() < 4) return s;
        int size{(int)s.size()};
        std::vector<std::vector<string>> dp(size+1, std::vector<string>(size+1, ""));
        for(int i{0}; i < size; ++i) dp[i][i+1] = s[i];
        for(int i{size-2}; i >= 0; --i) {
            for(int j{i+2}; j <= size; ++j) {
                dp[i][j] = encode(dp, s, i, j);
                for(int k{i}; k <= j; ++k)
                    if(dp[i][j].size() > dp[i][k].size() + dp[k][j].size()) dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
        return dp[0][size];
    }
    string encode(const std::vector<std::vector<string>>& dp, const string& s, int i, int j) {
        for(int k{1}, len{j-i}, stop{(j-i)/2}; k <= stop; ++k) {
            if(len % k) continue;
            bool valid{true};
            for(int l{i}, n{0}; l < j; ++l, ++n) {
                if(s[i+n%k] != s[l]) {
                    valid = false;
                    break;
                }
            }
            if(valid) return to_string(len/k)+'[' + dp[i][i+k] + ']'; // Need extra check here if encoding of same length is unwanted
        }
        return s.substr(i, j-i);
    }
};
