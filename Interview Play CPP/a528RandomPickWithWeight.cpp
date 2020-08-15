//
//  a528RandomPickWithWeight.cpp
//  Interview Play CPP
//
//  Created by jingtao ren on 8/14/20.
//  Copyright © 2020 Jingtao Ren. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<int, int> m_prefixWeightIndex;
    int m_totalWeight;
public:
    Solution(vector<int>& w) {
        int prefixWeight = 0;
        for (int i = 0; i < w.size(); ++i) {
            m_prefixWeightIndex[prefixWeight] = i;
            prefixWeight += w[i];
        }
        m_totalWeight = prefixWeight;
        
    }
    
    int pickIndex() {
        int pos = rand() % m_totalWeight;
        auto itr = m_prefixWeightIndex.lower_bound(pos);
        if (itr ->first != pos) {
            itr = prev(itr, 1);
        }
        return itr->second;
    }
};
