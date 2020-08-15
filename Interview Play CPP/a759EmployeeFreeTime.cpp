//
//  a759EmployeeFreeTime.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;
/*
class Solution {
private:
     vector<Interval> createMaster( vector<vector<Interval>>& schedule, int start, int end){
         vector<Interval> result;
         for(int i = 0; i < schedule.size(); i++){
             for(int j = 0; j < schedule[i].size(); j++)
                 result.push_back(schedule[i][j]);
         }
         
         auto comp = [](Interval& a, Interval& b){
           return a.start < b.start;
         };
         
         sort(result.begin(), result.end(), comp);
         return result;
     }
    
     vector<Interval> mergeIntervals(vector<Interval>& schedule){
         vector<Interval> result;
         result.push_back(schedule[0]);
         for(int i = 1; i < schedule.size(); i++){
             if(schedule[i].start <= result.back().end){
                 result.back().end = max(result.back().end, schedule[i].end);
             }
             else{
                 result.push_back(schedule[i]);
             }
         }
         return result;
     }
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> result;
        
        vector<Interval> master = createMaster(schedule, 0, schedule.size() -1);
        
        vector<Interval> merged = mergeIntervals(master);
        
        for(int i = 1; i < merged.size(); i++){
            Interval newInt(merged[i - 1].end, merged[i].start);
            result.push_back(newInt);
        }
        
        return result;
    }
};
*/
