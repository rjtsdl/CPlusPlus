//
//  a1064FixedPoint.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/22/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int l = 0, r = (int)A.size() - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (A[mid] - mid < 0)
                l = mid + 1;
            else
                r = mid;
        }
        return (A[l] == l)? l : -1;
    }
};
