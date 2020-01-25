//
//  a253MeetingRoomsII.cpp
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
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> points;
                
        for (auto v : intervals) {
            points[v[0]]++;
            points[v[1]]--;
        }
        
        vector<vector<int>> ret;
        
        int m = 0;
        int c = 0;
        int s = -1;
        for (auto p : points) {
            c += p.second;
            m = max(m, c);
            
        }
        
        return m;
        
    }
};
