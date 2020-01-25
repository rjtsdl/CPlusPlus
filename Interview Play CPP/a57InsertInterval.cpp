//
//  a57InsertInterval.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/24/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int, int> points;
        
        for (auto v : intervals) {
            points[v[0]]++;
            points[v[1]]--;
        }
        
        points[newInterval[0]]++;
        points[newInterval[1]]--;
        
        vector<vector<int>> ret;
        
        int c = 0;
        int s = -1;
        for (auto p : points) {
            c += p.second;
            if (s == -1) {
                s = p.first;
            }
            
            if (c  == 0) {
                ret.push_back({s, p.first});
                s = -1;
            }
            
        }
        
        return ret;
    }
};
