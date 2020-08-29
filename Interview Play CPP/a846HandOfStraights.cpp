//
//  a846HandOfStraights.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/28/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
       priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &n : hand)
            pq.push(n);
        while(pq.size()) {
            int n = pq.top();
            vector<int> temp;
            for(int i = n; i < n + W; i++) {
                if(pq.top() == i)
                    pq.pop();
                else
                    return false;
                // handle duplicates
                 while(pq.size() and pq.top() == i) {
                    pq.pop();
                    temp.push_back(i);
                }
            }
            // insert duplicates back
            for(auto &t : temp)
                pq.push(t);
        }
        return true;
    }
};
