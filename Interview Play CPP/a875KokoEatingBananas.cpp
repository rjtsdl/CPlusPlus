//
//  a875KokoEatingBananas.cpp
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
    int minEatingSpeed(vector<int>& piles, int H) {
        
        if (piles.size() > H) return -1;
        int maxE = *max_element(piles.begin(), piles.end());
        
        int rK = maxE;
        int lK = 1;
        
        while (lK < rK) {
            int mid = lK + (rK-lK)/2;
            if (canEat(piles, H, mid)) {
                rK = mid;
            } else {
                lK = mid+1;
            }
        }
        return rK;
        
    }
    
    bool canEat(vector<int>& piles, int H, int K) {
        int hour = 0;
        for (int p: piles) {
            hour += (p%K > 0 ? 1: 0) + p/K;
        }
        
        return hour <= H;
    }
};
