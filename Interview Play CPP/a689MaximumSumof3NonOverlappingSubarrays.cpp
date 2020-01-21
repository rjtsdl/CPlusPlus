//
//  a689MaximumSumof3NonOverlappingSubarrays.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /* Time limited
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<vector<vector<int>>> dp(nums.size()+k, vector<vector<int>>(4, vector<int>()));
        dp_run(nums, dp, k, 0, 3);
        return vector<int>(dp[0][3].begin()+1, dp[0][3].end());
        
    }
    
    int dp_run(vector<int>& nums, vector<vector<vector<int>>>& dp, int k, int start, int remaining) {
        if (remaining == 0  && start <= nums.size()) {
            dp[start][remaining] = vector<int>{0};
            return 0;
        }
        
        if (start >= nums.size() || remaining < 0) {
            return INT_MAX;
        }
        
        if (!dp[start][remaining].empty()) {
            // Already processed
            return dp[start][remaining][0];
        }
        
        dp[start][remaining] = vector<int>{INT_MAX};
        
        if (start + k > nums.size()) {
            return INT_MAX;
        }
        
        int cur =0;
        int i =0;
        while(start + i <= nums.size()) {
            if (i < k) {
                cur += nums[start + i];
            } else {
                //
                if (dp_run(nums, dp, k, start+i, remaining-1) != INT_MAX &&
                    dp[start+i][remaining-1][0] - cur < dp[start][remaining][0]) {
                    dp[start][remaining].clear();
                    dp[start][remaining].push_back(dp[start+i][remaining-1][0] - cur);
                    dp[start][remaining].push_back(start+i-k);
                    for (int j =1 ; j <dp[start+i][remaining-1].size(); ++j) {
                        dp[start][remaining].push_back(dp[start+i][remaining-1][j]);
                    }
                }
                if (start + i < nums.size()) cur += nums[start+i] - nums[start+i-k];
            }
            ++i;
        }
        
        
        return dp[start][remaining][0];
    }
     */
    
    // following is an easier approach
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(3);
        vector<pair<int, int>> left_max(n);
        vector<pair<int, int>> right_max(n);
        int max_sum = 0;
        // need 2 windows to slide from left or right
        int wleft = 0;
        for (int i = 0; i < k; ++i) {
            wleft += nums[i];
        }
        left_max[k-1].first = wleft;
        left_max[k-1].second = 0; // start from 0
        for (int i = 0; i < n-k; ++i) { // ith letter to be deleted
            wleft -= nums[i];
            wleft += nums[i+k];
            // take maximum
            if (left_max[i+k-1].first >= wleft) {
                left_max[i+k].first = left_max[i+k-1].first;
                left_max[i+k].second = left_max[i+k-1].second;
            }
            else {
                left_max[i+k].first = wleft;
                left_max[i+k].second = i+1;
            }
        }
        int wright = 0;
        for (int i = n-1; i >= n-k; --i) {
            wright += nums[i];
        }
        right_max[n-k].first = wright;
        right_max[n-k].second = n-k;
        for (int i = n-1; i >= k; --i) { // ith letter to be deleted
            wright -= nums[i];
            wright += nums[i-k];
            // take maximum
            if (wright >= right_max[i-k+1].first) {
                right_max[i-k].first = wright;
                right_max[i-k].second = i-k; // start is i-k
            }
            else {
                right_max[i-k].first = right_max[i-k+1].first;
                right_max[i-k].second = right_max[i-k+1].second;
            }
        }
        int start = k;
        int end = n-2*k;
        int wmiddle= 0;
        for (int i = start; i < start+k; ++i) {
            wmiddle += nums[i];
        }
        for (; start <= end; ++start) {
            int total = left_max[start-1].first + right_max[start+k].first + wmiddle;
            if (total > max_sum) {
                max_sum = total;
                result[0] = left_max[start-1].second;
                result[1] = start;
                result[2] = right_max[start+k].second;
            }
            wmiddle -= nums[start];
            wmiddle += nums[start+k];
        }
        return result;
    }
};
