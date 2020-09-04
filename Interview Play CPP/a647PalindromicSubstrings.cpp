//
//  a647PalindromicSubstrings.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 9/4/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        
        vector<char> A (2*s.size()+3);
        A[0] = '@';
        A[1] = '#';
        A[A.size() - 1] = '$';
        int t = 2;
        for (char c: s) {
            A[t++] = c;
            A[t++] = '#';
        }
        
        vector<int> Z(A.size());
        int center = 0, right = 0;
        for (int i = 1; i < Z.size() - 1; ++i) {
            if (i < right)
                Z[i] = min(right - i, Z[2 * center - i]);
            while (A[i + Z[i] + 1] == A[i - Z[i] - 1])
                Z[i]++;
            if (i + Z[i] > right) {
                center = i;
                right = i + Z[i];
            }
        }
        int ans = 0;
        for (int v: Z) ans += (v + 1) / 2;
        return ans;
    }
};
