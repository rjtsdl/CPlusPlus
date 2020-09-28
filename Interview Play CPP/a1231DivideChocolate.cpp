//
//  a1231DivideChocolate.cpp
//  Interview Play CPP
//
//  Created by Jingtao Ren on 9/27/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int n = K + 1;
        int start = *std::min_element(sweetness.begin(), sweetness.end());
        int end = std::accumulate(sweetness.begin(), sweetness.end(), 0)/n+1;
        while(start < end)
        {
            int mid = start + (end - start+1)/2;
            int sum = 0;
            int cnt = 0;
            for(int i : sweetness)
            {
                sum += i;
                if(sum >= mid)
                {
                    cnt++;
                    sum = 0;
                }
            }
            if(cnt >= n) start = mid;
            else end = mid-1;
        }
        return start;
    }
};
