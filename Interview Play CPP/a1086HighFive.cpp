//
//  a1086HighFive.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/17/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        
        map<int,priority_queue<int>> mapSum;
        
        vector<vector<int>> Avg;
        
        for(int i = 0; i < items.size(); i++)
        {
            mapSum[items[i][0]].push(items[i][1]);
        }
        
        for(auto itr = mapSum.begin(); itr != mapSum.end();itr++)
        {
            int stdId = itr->first;
            int avgSum = 0;
            int NbOfScores = 0;
            vector<int> temp;
            for(int i = 0; (i < 5 && !itr->second.empty()); i++)
            {
                
                avgSum = avgSum + itr->second.top();
                itr->second.pop();
                NbOfScores++;
            }
            
            avgSum = avgSum/NbOfScores;
            temp.push_back(stdId);
            temp.push_back(avgSum);
            Avg.push_back(temp);
                    
        }
        
        return Avg;
    }
};
