//
//  a435NonoverlappingIntervals.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 10/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        return removeOverlap(intervals, 0, INT_MIN);
        
    }
    
    int removeOverlap(vector<vector<int>>& intervals, int offset, int previousRight) {
        if (intervals.size() == offset) return 0;
        else if (intervals[offset][0] >= previousRight) {
            return removeOverlap(intervals, offset+1, intervals[offset][1]);
        } else {
            return 1 + removeOverlap(intervals, offset+1, min(previousRight, intervals[offset][1]));
        }
    }
};
