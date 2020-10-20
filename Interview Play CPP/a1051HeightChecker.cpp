//
//  a1051HeightChecker.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/20/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy = heights;
        sort(copy.begin(), copy.end());
        int swaps = 0;
        for (int i=0;i<heights.size();i++) {
            if (heights[i] != copy[i]) swaps++;
        }
        return swaps;
    }
};
