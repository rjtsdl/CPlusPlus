//
//  a852PeakIndexinaMountainArray.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/18/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int peekV = arr[0];
        int peekIdx = 0;
        
        for (int i = 1; i < arr.size()-1; i++) {
            if (arr[i] > peekV) {
                peekV = arr[i];
                peekIdx = i;
            }
        }
        
        return peekIdx;
        
    }
};
