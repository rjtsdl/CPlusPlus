//
//  a1243ArrayTransformation.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 1/10/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        while (transformArrayInPlace(arr));
        return arr;
    }
    
    
    bool transformArrayInPlace(vector<int>& arr) {
        bool changed = false;
        if (arr.size() < 3) return changed;
        int prev = 0;
        for (int i =1; i < arr.size()-1; ++i) {
            int kp = arr[i-1];
            if (prev != 0) changed |= true;
            arr[i-1] += prev;
            
            if (arr[i] > kp && arr[i] > arr[i+1]) {
                prev = -1;
            } else if (arr[i] < kp && arr[i] < arr[i+1]) {
                prev = 1;
            } else {
                prev = 0;
            }
        }
        
        if (prev != 0) {
            changed |= true;
            arr[arr.size()-2] += prev;
        }
        
        return changed;
    }
    
};
