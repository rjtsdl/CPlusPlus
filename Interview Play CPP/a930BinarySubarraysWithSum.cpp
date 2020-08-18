//
//  a930BinarySubarraysWithSum.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int su = 0;
        for (int x: A) su += x;

        // indexes[i] = location of i-th one (1 indexed)
        vector<int> indexes(su+2, 0);
        indexes[0] = -1;
        int t = 1;
        for (int i = 0; i < A.size(); ++i)
            if (A[i] == 1)
                indexes[t++] = i;
        indexes[t] = A.size();

        int ans = 0;
        if (S == 0) {
            for (int i = 0; i < indexes.size() - 1; ++i) {
                // w: number of zeros between consecutive ones
                int w = indexes[i+1] - indexes[i] - 1;
                ans += w * (w + 1) / 2;
            }
            return ans;
        }

        for (int i = 1; i < indexes.size() - S; ++i) {
            int j = i + S - 1;
            int left = indexes[i] - indexes[i-1];
            int right = indexes[j+1] - indexes[j];
            ans += left * right;
        }

        return ans;
    }
};
