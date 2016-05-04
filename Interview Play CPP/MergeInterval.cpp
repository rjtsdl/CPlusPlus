//
//  MergeInterval.cpp
//  Interview Play CPP
//
//  Created by Jingtao on 5/3/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;


// * Definition for an interval.
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::sort(
                  intervals.begin(),
                  intervals.end(),
                  [](Interval a, Interval b){
                      return a.start < b.start;}
                  );
        vector<Interval> res;
        for (auto& it : intervals) {
            if (res.empty()) {
                res.push_back(it);
            }
            else
            {
                Interval back = res.back();
                if (isOverlap(it, back)) {
                    res.pop_back();
                    res.push_back(mergeTwoInterval(it, back));
                }
                else
                {
                    res.push_back(it);
                }
            }
        }
        return res;
    }
    
    bool isOverlap(const Interval& ia, const Interval& ib)
    {
        if (ia.end < ib.start || ia.start > ib.end) {
            return false;
        }
        return true;
    }
    
    Interval mergeTwoInterval(const Interval& ia, const Interval& ib)
    {
        // I assume we already know it is overlapped
        return Interval(std::min(ia.start, ib.start), std::max(ia.end, ib.end));
    }
};