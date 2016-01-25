//
//  TrapRainWater.cpp
//  Interview Play CPP
//
//  Created by rjtsdl on 1/24/16.
//  Copyright © 2016 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

// INSIGHT
// left to right, then right to left
// I guess, the reason why this algo works, is, the water is trapped by left and right bars.
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> waterLevels;
        for (auto& h : height) {
            waterLevels.push_back(0);
        }
        
        int prevLevel = 0;
        for (int i =0; i< height.size(); ++i) {
            if (height[i] > prevLevel) {
                prevLevel = height[i];
            }
            waterLevels[i] = prevLevel;
        }
        prevLevel = 0;
        for (int j= height.size() -1 ; j >=0; --j) {
            if (height[j] > prevLevel) {
                prevLevel = height[j];
            }
            waterLevels[j] = min(waterLevels[j], prevLevel);
        }
        int waterAmount = 0;
        for (int i = 0; i<height.size(); ++i) {
            waterAmount += waterLevels[i] - height[i];
        }
        return waterAmount;
    }
};