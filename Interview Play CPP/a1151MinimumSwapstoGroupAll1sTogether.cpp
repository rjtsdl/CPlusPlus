//
//  a1151MinimumSwapstoGroupAll1sTogether.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int minSwaps(vector<int>& data) {
        
        int n = data.size();
        
        int maxWindow = 0;
        for (int i = 0; i < n; i++)
            maxWindow += ((data[i] == 1) ? 1 : 0);
        
        int i = 0, countOnes = 0;
        for (i = 0; i < maxWindow; i++) {
            if (data[i] == 1)
                countOnes++;
        }
        
        int res = countOnes;
        for (; i < n; i++) {
            if (data[i] == 1) countOnes++;
            if (data[i-maxWindow] == 1) countOnes--;
            res = max(res, countOnes);
        }
        
        return maxWindow-res;
    }
};
