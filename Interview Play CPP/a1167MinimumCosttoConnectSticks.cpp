//
//  a1167MinimumCosttoConnectSticks.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/30/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.empty())
            return 0;
        priority_queue<int,vector<int>,greater<int>>queue;
        for(auto &stick:sticks)
        {
            queue.push(stick);
        }
        int sumOfSticks{0};
        while(queue.size()!=1)
        {
            int stick1=queue.top();
            queue.pop();
            int stick2=queue.top();
            queue.pop();
            int temp=stick1+stick2;
            sumOfSticks+=temp;
            queue.push(temp);
        }
        return sumOfSticks;
    }
};
