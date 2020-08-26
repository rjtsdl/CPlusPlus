//
//  a658FindKClosestElements.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/26/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if (x < arr[0]) {
            res.insert(res.end(), arr.begin(), arr.begin()+k);
            return res;
        }
        
        if (x > arr.back()) {
            res.insert(res.end(), prev(arr.end(), k), arr.end());
            return res;
        }
        
        auto lb = lower_bound(arr.begin(), arr.end(), x);
        int lbIndex = lb - arr.begin();
        
        int low = max(0, lbIndex-k-1);
        int high = min((int)arr.size()-1, lbIndex + k -1);
        while (high - low > k -1) {
            if (low < 0 || x - arr[low] <= arr[high]-x) high--;
            else if (high > arr.size()-1 || x - arr[low] > arr[high]-x) low++;
            else {
                // nothing
            }
        }
        
        res.insert(res.end(), next(arr.begin(), low), next(arr.begin(),high+1));
        return res;
    }
};
