//
//  a1229MeetingScheduler.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/16/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int i1 =0, i2=0;
        
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        while (i1 < slots1.size() && i2 < slots2.size()) {
            while (i1 < slots1.size() && slots1[i1][1] - slots1[i1][0] < duration) ++i1;
            while (i2 < slots2.size() && slots2[i2][1] - slots2[i2][0] < duration) ++i2;
            if (i1 == slots1.size() || i2 == slots2.size()) return {};
            
            
            if (slots1[i1][0] <= slots2[i2][0]) {
                if (slots1[i1][1] >= slots2[i2][0] + duration && slots2[i2][1] >= slots2[i2][0] + duration) {
                    return {slots2[i2][0], slots2[i2][0] + duration};
                }
                i1++;
            } else {
                if (slots1[i1][1] >= slots1[i1][0] + duration && slots2[i2][1] >= slots1[i1][0] + duration) {
                    return {slots1[i1][0], slots1[i1][0] + duration};
                }
                i2++;
            }
        }
        return {};
    }
};
